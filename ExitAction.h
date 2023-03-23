#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
class ExitAction :public Action
{
	GfxInfo RectGfxInfo;
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	ExitAction(ApplicationManager* pApp);
	virtual void Undo();
	~ExitAction();
};
