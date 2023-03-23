#pragma once
#include "Actions/Action.h"
#include "GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"

class StopRecording : public Action
{
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	StopRecording(ApplicationManager* pApp);
	virtual void Undo();
};
