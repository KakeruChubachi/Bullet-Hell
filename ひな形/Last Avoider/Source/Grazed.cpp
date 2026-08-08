#include "Grazed.h"

namespace
{
	int grazedCount = 0;
}

void Grazed::Init()
{
	grazedCount = 0;
}

void Grazed::AddGrazed(int grazed)
{
	grazedCount += grazed;
}

int Grazed::Get()
{
	return grazedCount;
}
