#pragma once
#include "Engine/ConsoleObject.h"
class GameBlock  : public ConsoleObject 
{
public:
	//construcuter destructer
	GameBlock();
	~GameBlock();

	//delete Function
	GameBlock(const GameBlock& _Other) = delete;
	GameBlock(GameBlock&& _Other) noexcept = delete;
	GameBlock& operator=(const GameBlock& _Other) = delete;
	GameBlock& operator=(GameBlock&& _Other) noexcept = delete;

protected:

private:

};

