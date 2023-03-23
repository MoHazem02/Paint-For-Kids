#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "..\GUI\Output.h"
class SelectOrange : public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	SelectOrange(ApplicationManager* pApp);
	~SelectOrange();
	virtual void Undo();
};

