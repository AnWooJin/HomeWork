#pragma once
#include "ConsoleObject.h"

class Monster : public ConsoleObject
{
public:
	//construcuter destructer
	Monster();
	Monster(TextScreen* _Screen, const char* _Text, const ConsoleVector& _Pos);
	~Monster();

	//delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	void Update();

protected:

private:
};

