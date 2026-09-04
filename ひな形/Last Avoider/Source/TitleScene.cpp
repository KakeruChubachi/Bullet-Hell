#include "TitleScene.h"
#include"Screen.h"
TitleScene::TitleScene()
{
	hImage = LoadGraph("data/Image/Stardust-Swirl2.jpg");
}
TitleScene::~TitleScene()
{
}
void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}

	// 操作説明の表示切替（Hキー、押した瞬間だけ反応させる）
	bool nowHKey = CheckHitKey(KEY_INPUT_H) != 0;
	if (nowHKey && !prevHKey)
	{
		showHelp = !showHelp;
	}
	prevHKey = nowHKey;

	flasingTimer += Time::DeltaTime();
}
void TitleScene::Draw()
{
	int w, h;
	GetGraphSize(hImage, &w, &h);
	int srcX = (w - h) / 2;
	DrawRectExtendGraph(0, 0, 1280, 1280, srcX, 0, h, h, hImage, TRUE);

	SetFontSize(50);
	int textWidth = GetDrawStringWidth("Last Avoider", 12, 50);
	int x = (Screen::WIDTH - textWidth) / 2;
	int textHeight = GetDrawStringWidth("Last Avoider", 12, 50);
	int y = (Screen::HEIGHT - textHeight) / 2;
	DrawString(x, y, "Last Avoider", GetColor(0, 0, 0));

	SetFontSize(16);
	int textWidth2 = GetDrawStringWidth("[P]キーでスタート", 26, 16);
	int x2 = (Screen::WIDTH - textWidth2) / 2;
	int textHeight2 = GetDrawStringWidth("[P]キーでスタート", 26, 16);
	int y2 = (Screen::HEIGHT - textHeight2) / 2 + 100;
	if (flasingTimer >= 0.0f)
	{
		if (((int)flasingTimer / 1) % 2 == 0)
		{
			DrawString(x2, y2 - 100, "[P]キーでスタート", GetColor(0, 0, 0));
		}
	}

	// 操作説明の表示案内（画面中央、Pキー案内の少し下に常時表示）
	SetFontSize(16);
	int helpTextWidth = GetDrawStringWidth("[H]キーで操作説明を表示", 34, 16);
	int helpX = (Screen::WIDTH - helpTextWidth) / 2;
	int helpY = (Screen::HEIGHT / 2) + 40;
	DrawString(helpX, helpY, "[H]キーで操作説明を表示", GetColor(0, 0, 0));

	// 操作説明本体（showHelpがtrueのときだけ表示）
	if (showHelp)
	{
		int boxX = 100, boxY = 150, boxW = Screen::WIDTH - 200, boxH = 300;
		DrawBox(boxX, boxY, boxX + boxW, boxY + boxH, GetColor(0, 0, 0), TRUE);
		DrawBox(boxX, boxY, boxX + boxW, boxY + boxH, GetColor(255, 255, 255), FALSE);

		SetFontSize(20);
		DrawString(boxX + 30, boxY + 30, "=== 操作方法 ===", GetColor(255, 255, 255));
		DrawString(boxX + 30, boxY + 80, "W / A / S / D : 移動", GetColor(255, 255, 255));
		DrawString(boxX + 30, boxY + 110, "LSHIFT (長押し) : 低速移動", GetColor(255, 255, 255));
		DrawString(boxX + 30, boxY + 140, "SPACE : ショット", GetColor(255, 255, 255));
		DrawString(boxX + 30, boxY + 170, "P : ゲーム開始", GetColor(255, 255, 255));
		DrawString(boxX + 30, boxY + 200, "ESC : 終了", GetColor(255, 255, 255));
	}
}