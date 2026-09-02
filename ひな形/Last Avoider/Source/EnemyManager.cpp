#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	spawnTimer = 0;
	phaseNumber = 0;
	spawnInterval = 60;
	phaseMaxNumber = 2;
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::Update()
{
	spawnTimer++;
	if (spawnTimer >= spawnInterval)
	{
		if (phaseNumber < phaseMaxNumber)
		{
			phaseNumber++;
			new Enemy(100, 200, 52);
		}
		spawnTimer = 0;
	}
}

void EnemyManager::Draw()
{

}

