#include "AddHexagonAction.h"


AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexagonAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New hexagon: Click at the center");

	//Read the center of the hexagon
	pIn->GetPointClicked(Center.x, Center.y);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexagonAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(Center, RectGfxInfo);

	//Add the Hexagon to the list of figures
	if (pManager->IsRecording == true)
		pManager->AddRecordedFigure(H);
	else
		pManager->AddFigure(H);

}
//To BE MODIFIED
void AddHexagonAction::Undo()
{
	//pManager->DeleteFig(ID);
}