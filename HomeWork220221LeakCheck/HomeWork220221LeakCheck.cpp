
#include "Engine/ConsoleScreen.h"
#include "Engine/ConsoleRandom.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include "Head.h"
#include "Body.h"
#include "GlobalGameLogic.h"
int main()
{
	//_CrtSetBreakAlloc(172);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ConsoleScreen::GetInst().CreateScreen(10, 10, "□");

	ConsoleObject* NewHead = new Head(); 
	NewHead->Init({ 5,5 }, "★");

	ConsoleObject* NewBody = GlobalGameLogic::CreateBodyLogic(NewHead);
	
	while (true)
	{
		if (nullptr == NewBody)
		{
			NewBody = GlobalGameLogic::CreateBodyLogic(NewHead);
		}

		ConsoleScreen::GetInst().RenderStart();

		NewBody->Render();
		NewHead->Render();

		ConsoleScreen::GetInst().RenderEnd();

		NewBody->Update();
		NewHead->Update();
		if (true == NewHead->GetIsDeath())
		{
			break;
		}

		if (NewHead->OverLapCheck(NewBody))
		{
			NewHead->OverLap(NewBody);
			delete NewBody;
			NewBody = nullptr;
		}
	}
	if (nullptr != NewBody)
	{
		delete NewBody;
		NewBody = nullptr;
	}
	
	if (nullptr != NewHead)
	{
		delete NewHead;
		NewHead = nullptr;
	}
	ConsoleScreen::Destroy();
}	
