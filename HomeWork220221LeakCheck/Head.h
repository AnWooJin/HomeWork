#pragma once
#include <list>
#include "GameBlock.h"

class Body;
class Head : public GameBlock
{
public:
	//construcuter destructer
	Head();
	~Head();

	//delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

protected:
	void Update() override;

	void OverLap(ConsoleObject* _Other) override;
	
private:
	std::list<Body*>AllBody;
};

