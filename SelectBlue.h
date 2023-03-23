#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "..\GUI\Output.h"
class SelectBlue :  public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	SelectBlue(ApplicationManager* pApp);
	~SelectBlue();
	virtual void Undo();
};

