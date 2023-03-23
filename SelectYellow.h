#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "..\GUI\Output.h"
class SelectYellow :public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	SelectYellow(ApplicationManager* pApp);
	~SelectYellow();
	virtual void Undo();
};

