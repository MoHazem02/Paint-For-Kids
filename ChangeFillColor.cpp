#include "ChangeFillColor.h"
ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) : Action(pApp)
{
}
void ChangeFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please Choose a color to fill: ");
}
void ChangeFillColor::Execute()
{
	ReadActionParameters();
	pManager->ReadyToChangeDrawColor = false;
	pManager->ReadyToChangeFillColor = true;
}
ChangeFillColor::~ChangeFillColor()
{
}
void ChangeFillColor::Undo()
{
}
