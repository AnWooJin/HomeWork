#include "ConsoleGlobalInst.h"

TextScreen MainScreen(10, 10, "¤±");
Monster* AllMonsters = new Monster[10];
Player MainPlayer(&MainScreen, "¡Ú");

void AllDelete()
{
	if (nullptr != AllMonsters)
	{
		delete[] AllMonsters;
		AllMonsters = nullptr;
	}

}