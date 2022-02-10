#pragma once
#include "ConsoleMath.h"
#include "TextScreen.h"

class ConsoleObject
{
public:
	//construcuter destructer
	ConsoleObject(
		TextScreen* _Screen,
		const char* _Text,
		const ConsoleVector& _Pos);

	~ConsoleObject();

	//delete Function
	ConsoleObject(const ConsoleObject& _Other) = delete;
	ConsoleObject(ConsoleObject&& _Other) noexcept = delete;
	ConsoleObject& operator=(const ConsoleObject& _Other) = delete;
	ConsoleObject& operator=(ConsoleObject&& _Other) noexcept = delete;

	ConsoleVector GetPos()
	{
		return Pos_;
	}

	void SetPos(ConsoleVector _Value)
	{
		Pos_ = _Value;
	}

	void SetMove(ConsoleVector _Value)
	{
		ConsoleVector ResultPos;
		ResultPos = Pos_ + _Value;
		if (ResultPos.x_ < 0)
		{
			return;
		}
		if (ResultPos.x_ > Screen_->GetSize().x_ - 1)
		{
			return;
		}
		if (ResultPos.y_ < 0)
		{
			return;
		}
		if (ResultPos.y_ > Screen_->GetSize().y_ -1)
		{
			return;
		}
		Pos_ += _Value;
	}

	void Render();

protected:

private:
	// Has a 개념이라고 합니다.
	// 플레이어는 어차피 너무나도 많아
	// 만약 이 개념이 각자의 것을 가져야 한다면
	// 값이나 동적할당된 자신만의 메모리를 가져야 한다.
	TextScreen* Screen_;
	ConsoleVector Pos_;

	char Text_[3];
};

