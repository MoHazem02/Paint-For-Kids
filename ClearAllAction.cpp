#include "ClearAllAction.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) : Action(pApp)
{
}
void ClearAllAction::ReadActionParameters()
{
}
void ClearAllAction::Execute()
{
	pManager->DeleteAll();
}
ClearAllAction::~ClearAllAction()
{
}
void ClearAllAction::Undo()
{
}
