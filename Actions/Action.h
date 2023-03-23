#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	Action* AddActions[200];
	int ActionCount;


public:

	Action(ApplicationManager* pApp) { pManager = pApp; ActionCount = 0; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

#endif