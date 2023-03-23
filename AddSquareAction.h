#pragma once
# include "Actions/Action.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
# include "CSquare.h"
//Add square Action class
class AddSquareAction : public Action
{
private:
	Point Center; //square center
	GfxInfo RectGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
	virtual void Undo();
};


