#pragma once
#include "Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
class ClearAllAction : public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	ClearAllAction(ApplicationManager* pApp);
	~ClearAllAction();
	virtual void Undo();
};

