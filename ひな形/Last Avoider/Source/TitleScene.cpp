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
	flasingTimer += Time::DeltaTime();
}


void TitleScene::Draw()
{
	int w, h;
	GetGraphSize(hImage, &w, &h);
	int srcX = (w - h) / 2;
	DrawRectExtendGraph(0, 0, 1280,1280,srcX,0,h,h,hImage, TRUE);
	/*extern const char* Version();
	DrawString(0, 20, Version(), GetColor(255,255,255));*/
	SetFontSize(50);
	int textWidth = GetDrawStringWidth("Last Avoider", 12, 50);
	int x = (Screen::WIDTH - textWidth) / 2;
	int textHeight = GetDrawStringWidth("Last Avoider", 12, 50);
	int y = (Screen::HEIGHT - textHeight) / 2;
	DrawString(x, y, "Last Avoider", GetColor(0, 0, 0));
	//DrawFormatString(100, 100, GetColor(255,255,255), "%4.1f", 1.0f / Time::DeltaTime());
	SetFontSize(16);
	int textWidth2 = GetDrawStringWidth("Push [P]Key To Play", 20, 16);
	int x2 = (Screen::WIDTH - textWidth2) / 2;
	int textHeight2 = GetDrawStringWidth("Push [P]Key To Play", 20, 16);
	int y2 = (Screen::HEIGHT - textHeight2) / 2 + 100;
	if (flasingTimer >= 0.0f)
	{
		if (((int)flasingTimer / 1) % 2 == 0)
		{
			DrawString(x2, y2 - 100, "Push [P]Key To Play", GetColor(0, 0, 0));
		}
	}
	
}
