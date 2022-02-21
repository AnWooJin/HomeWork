#pragma once
#include "Engine/ConsoleObject.h"


class GlobalGameLogic
{
public:
	static ConsoleObject* CreateBodyLogic(const ConsoleObject* _Player);

protected:

private:
	//construcuter destructer
	GlobalGameLogic();
	~GlobalGameLogic();

	//delete Function
	GlobalGameLogic(const GlobalGameLogic& _Other) = delete;
	GlobalGameLogic(GlobalGameLogic&& _Other) noexcept = delete;
	GlobalGameLogic& operator=(const GlobalGameLogic& _Other) = delete;
	GlobalGameLogic& operator=(GlobalGameLogic&& _Other) noexcept = delete;

};

