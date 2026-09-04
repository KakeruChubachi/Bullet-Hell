#include "EnemyManager.h"
#include"EnemyStraight.h"
#include"EnemySine.h"
#include "../Library/ObjectManager.h"

EnemyManager::EnemyManager()
{
	spawnTimer = 0;
	phaseNumber = 0;
	spawnIntervals[0] = 60;
	spawnIntervals[1] = 60*15;
	spawnIntervals[2] = 60*25;
	phaseMaxNumber = 3;
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::Update()
{
	spawnTimer++;
	if (spawnTimer >= spawnIntervals[phaseNumber])
	{
		if (phaseNumber < phaseMaxNumber)
		{
			phaseNumber++;
			if (phaseNumber == 1)
			{
				new EnemyStraight(200, 52, 52);
				new EnemyStraight(400, 52, 52);
				new EnemyStraight(600, 52, 52);
				new EnemyStraight(800, 52, 52);
				new EnemyStraight(1000, 52, 52);
			}
			else if (phaseNumber == 2)
			{
				new EnemySine(300*2, 52, 52);
				new EnemySine(100*2, 52, 52);
				new EnemySine(500*2, 52, 52);
			}
				
			else if (phaseNumber == 3)
			{
				new Enemy(100, 200, 52);
				new Enemy(300, 200, 52);
				new Enemy(500, 200, 52);
				new Enemy(700, 200, 52);
				new Enemy(900, 200, 52);
			}
				
		}
		spawnTimer = 0;
	}
}

void EnemyManager::Draw()
{

}

bool EnemyManager::IsAllCleared()
{
	if (phaseNumber < phaseMaxNumber) return false; // ‚Ü‚¾oŒ»‚µØ‚Á‚Ä‚¢‚È‚¢
	return FindGameObjects<Enemy>().empty();        // “G‚ª1‘Ì‚àŽc‚Á‚Ä‚¢‚È‚¢
}