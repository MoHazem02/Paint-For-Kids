#pragma once
#include "Actions/Action.h"
#include "CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

//Add hexagon Action class
class AddHexagonAction : public Action
{
private:
	Point Center; //hexagon center
	GfxInfo RectGfxInfo;
public:
	AddHexagonAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();
	virtual void Undo();
};
