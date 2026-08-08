#pragma once
/// <summary>
/// グレイズ機能を管理します
/// </summary>
namespace Grazed
{
	// グレイズを初期化する(シーン開始時などに呼ぶ)
	void Init();

	// グレイズ数を加算する
	void AddGrazed(int grazed);

	// 現在のグレイズ数を取得する
	int Get();
}

