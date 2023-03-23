#include "AddCircleAction.h"


AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New circle: Click at the center");

	//Read the center and store in point center
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New circle: Click at radius");

	//Read a point on the circle and store in the radius
	pIn->GetPointClicked(Radius.x, Radius.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle* C = new CCircle(Center, Radius, RectGfxInfo);

	//Add the circle to the list of figures
	if (pManager->IsRecording == true)
		pManager->AddRecordedFigure(C);
	//Add the circle to the list of figures
	else
		pManager->AddFigure(C);

}
void AddCircleAction::Undo()
{
	//pManager->DeleteFig(ID);
}
