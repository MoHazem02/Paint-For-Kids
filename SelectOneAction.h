#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "GUI/Input.h"
# include "GUI/Output.h"
#include "ApplicationManager.h"
class SelectOneAction :public Action
{
protected:
	Point ClickedPoint;
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	SelectOneAction(ApplicationManager* pApp);
	virtual void Undo();
};

