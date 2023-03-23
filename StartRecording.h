#pragma once
#include "Actions/Action.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"

class StartRecording : public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	StartRecording(ApplicationManager* pApp);
	virtual void Undo();
};
