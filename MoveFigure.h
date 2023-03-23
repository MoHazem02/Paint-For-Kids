#pragma once
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
#include "Actions/Action.h"
class MoveFigure : public Action
{
	Point P1;

public:
	MoveFigure(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};