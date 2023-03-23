#pragma once

#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Actions/Action.h"
#include "CCircle.h"

//Add circle Action class
class AddCircleAction : public Action
{
private:
	Point Center, Radius; 
	GfxInfo RectGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();
	virtual void Undo();
};

