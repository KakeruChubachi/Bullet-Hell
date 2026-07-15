#include "Score.h"

namespace
{
	int score = 0;
}

void Score::Init()
{
	score = 0;
}

void Score::Add(int point)
{
	score += point;
}

int Score::Get()
{
	return score;
}