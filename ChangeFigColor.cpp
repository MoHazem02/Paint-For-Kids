#include "ChangeFigColor.h"
ChangeFigColor::ChangeFigColor(ApplicationManager* pApp) : Action(pApp)
{
}
void ChangeFigColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please Choose a color: ");
}
void ChangeFigColor::Execute()
{
	ReadActionParameters();
	pManager->ReadyToChangeDrawColor = true;
	pManager->ReadyToChangeFillColor = false;
}
ChangeFigColor::~ChangeFigColor()
{
}
void ChangeFigColor::Undo()
{
}
