#include "DxLib.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	DxLib_Init();
	LoadGraphScreen(288, 400, "Data/Image/material/PNG/playerShip2_red.png", FALSE);
	WaitKey();
	DxLib_End();
	return 0;
}