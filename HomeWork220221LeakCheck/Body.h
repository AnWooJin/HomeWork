#pragma once
class Body
{
public:
	//construcuter destructer
	Body();
	~Body();
	int a = 10;
	//delete Function
	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

protected:

private:

};

