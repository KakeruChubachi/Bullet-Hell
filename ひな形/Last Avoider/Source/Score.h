#pragma once
/// <summary>
/// スコアを管理します
/// </summary>
namespace Score
{
	// スコアを初期化する(シーン開始時などに呼ぶ)
	void Init();

	// スコアを加算する
	void Add(int point);

	// 現在のスコアを取得する
	int Get();
}