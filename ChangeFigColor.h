#pragma once
#include "Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
class ChangeFigColor : public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	ChangeFigColor(ApplicationManager* pApp);
	~ChangeFigColor();
	virtual void Undo();
};

