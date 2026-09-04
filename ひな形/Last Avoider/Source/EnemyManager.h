#pragma once
#include"Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void Update();
	void Draw();
	bool IsAllCleared(); // ← 追加：全フェーズ出現済み＋敵0体ならtrue
private:
	int spawnTimer;
	int phaseNumber;
	int spawnIntervals[3];
	int phaseMaxNumber;
};

