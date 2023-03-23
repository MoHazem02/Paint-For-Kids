#pragma once
#include "Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
class ChangeFillColor : public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	ChangeFillColor(ApplicationManager* pApp);
	~ChangeFillColor();
	virtual void Undo();
};

