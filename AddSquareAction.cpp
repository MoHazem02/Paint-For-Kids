#include "AddSquareAction.h"


AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New square: at the center");

	//Read the center of the square 
	pIn->GetPointClicked(Center.x, Center.y);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square with the parameters read from the user
	CSquare* S= new CSquare(Center, RectGfxInfo);

	//Add the square to the list of figures
	if (pManager->IsRecording == true)
		pManager->AddRecordedFigure(S);
	else
		pManager->AddFigure(S);

}
void AddSquareAction::Undo()
{
	//pManager->DeleteFig(ID);
}
