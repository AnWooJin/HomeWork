#include "TextScreen.h"
#include <iostream>

TextScreen::TextScreen(int _Width, int _Height, const char* _DefaultValue)
	: PixelData_(nullptr)
	, Size_(0,0)
	, DefaultPixel_()
{
	CreateScreen(_Width, _Height, _DefaultValue);
}

TextScreen::~TextScreen()
{
	for (int i = 0; i < Size_.y_; i++)
	{
		if (nullptr != PixelData_)
		{
			delete[] PixelData_[i];
			PixelData_[i] = nullptr;
		}
	}

	if (nullptr != PixelData_)
	{
		delete[] PixelData_;
		PixelData_ = nullptr;
	}
}

void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	Size_.x_ = _Width;
	Size_.y_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	int RealWidth = Size_.x_ * 2;
	RealWidth += 2;

	PixelData_ = new char* [Size_.y_];

	for (int i = 0; i < Size_.y_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}

}

void TextScreen::SettingScreen()
{
	for (int y = 0; y < Size_.y_; y++)
	{
		for (int x = 0; x < Size_.x_; x++)
		{
			for (int i = 0; i < 2; i++)
			{
				PixelData_[y][(x * 2) + i] = DefaultPixel_[i];
			}
		}
		PixelData_[y][(Size_.x_ * 2)] = '\n';
		PixelData_[y][(Size_.x_ * 2) + 1] = 0;
	}
}

void TextScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < Size_.y_; y++)
	{
		printf_s(PixelData_[y]);
	}
}

// 대부분의 상황에서 이걸로 쓰겠지만
void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue)
{
	SetPixel(_Pos.x_, _Pos.y_, _DefaultValue);
}

// 원론함수가 없으면 세세한 조정을 못할 때가 있기 때문에
// 2가지 함수를 굳이 구현하게 됩니다.
// 코드는 사용성이 좋아야 합니다.

void TextScreen::SetPixel(int _X, int _Y, const char* _DefaultValue)
{
	for (int i = 0; i < 2; i++)
	{
		PixelData_[_Y][(_X * 2) + i] = _DefaultValue[i];
	}
}