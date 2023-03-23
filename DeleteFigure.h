#pragma once
#include "Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectOneAction.h"
class DeleteFigure:public Action
{
	
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	DeleteFigure(ApplicationManager* pApp);
	~DeleteFigure();
	virtual void Undo();

};

