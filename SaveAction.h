#pragma once
#include "Actions/Action.h"
#include "GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"
#include <fstream>
class SaveAction: public Action
{
	string FileName;
	ofstream savedFile;
public:
	virtual void ReadActionParameters();
	virtual void Execute();
	SaveAction(ApplicationManager* pApp);
	virtual void Undo();
};

