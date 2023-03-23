#pragma once
#include "Actions/Action.h"
#include "GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
#include <fstream>
class LoadAction : public Action
{
	string FileName;
	ifstream loadFile;
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	LoadAction(ApplicationManager* pApp);
	virtual void Undo();
};

