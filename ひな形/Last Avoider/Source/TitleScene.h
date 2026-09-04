#pragma once
#include "../Library/SceneBase.h"
/// <summary>
/// タイトルシーン
/// 
/// タイトルを表示して、キーを押したらプレイシーンに移行する。
/// </summary>
class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	float flasingTimer = 0.0f;
	bool showHelp = false;      // 追加：操作説明の表示中フラグ
	bool prevHKey = false;      // 追加：Hキーの前フレーム状態（トグル判定用）
};