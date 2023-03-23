#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
class FillShape : public Action
{
	GfxInfo RectGfxInfo;
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	FillShape(ApplicationManager* pApp);
	virtual void Undo();
};
