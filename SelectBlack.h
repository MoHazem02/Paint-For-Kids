#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "..\GUI\Output.h"
class SelectBlack : public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	SelectBlack(ApplicationManager* pApp);
	~SelectBlack();
	virtual void Undo();
};

