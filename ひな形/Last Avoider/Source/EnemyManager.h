#pragma once
#include"Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void Update();
	void Draw();
private:
	int spawnTimer;
	int phaseNumber;
	int spawnInterval;
	int phaseMaxNumber;
};

