#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "..\GUI\Output.h"
class SelectGreen : public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	SelectGreen(ApplicationManager* pApp);
	~SelectGreen();
	virtual void Undo();

};

