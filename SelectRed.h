#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "..\GUI\Output.h"
class SelectRed :public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	SelectRed(ApplicationManager* pApp);
	~SelectRed();
	virtual void Undo();
};

