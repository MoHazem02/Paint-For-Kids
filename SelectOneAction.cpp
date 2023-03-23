#include "SelectOneAction.h"


SelectOneAction::SelectOneAction(ApplicationManager* pApp) : Action(pApp)
{
}


void SelectOneAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please Select a Figure");

	// read the point selected
	pIn->GetPointClicked(ClickedPoint.x, ClickedPoint.y);

}
void SelectOneAction::Execute()
{
	ReadActionParameters();
	pManager->UnselectAll();
	pManager->GetFigure(ClickedPoint.x, ClickedPoint.y);
}
void SelectOneAction::Undo()
{
}
