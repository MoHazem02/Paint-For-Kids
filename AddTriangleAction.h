#pragma once
# include "Actions/Action.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
# include "CTriangle.h"

//Add triangle Action class
class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3; // the three vertices of the triangle
	GfxInfo RectGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();
	virtual void Undo();
};


