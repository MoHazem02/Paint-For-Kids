#include "SelectBlue.h"
SelectBlue::SelectBlue(ApplicationManager* pApp) : Action(pApp)
{
}
void SelectBlue::ReadActionParameters()
{
}
void SelectBlue::Execute()
{
	Output* pOut = pManager->GetOutput();
	color A = pOut->ConvertToColorObj("BLUE");
	if (!pManager->ReadyToChangeDrawColor && !pManager->ReadyToChangeFillColor)
	{
		pOut->PrintMessage("Please Select Change Color First!");
		return;
	}
	else if (pManager->ReadyToChangeDrawColor)
	{
		pManager->ChangeSelectedDrawColor(A);
		UI.DrawColor = A;
	}
	else if (pManager->ReadyToChangeFillColor)
	{
		pManager->ChangeSelectedFillColor(A);
		UI.FillColor = A;
	}
	
}
SelectBlue::~SelectBlue()
{
	pManager->ReadyToChangeDrawColor = false;
	pManager->ReadyToChangeFillColor = false;
}
void SelectBlue::Undo()
{
}
