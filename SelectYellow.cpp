#include "SelectYellow.h"
SelectYellow::SelectYellow(ApplicationManager* pApp) : Action(pApp)
{
}
void SelectYellow::ReadActionParameters()
{
}
void SelectYellow::Execute()
{
	Output* pOut = pManager->GetOutput();
	color A = pOut->ConvertToColorObj("YELLOW");
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
SelectYellow::~SelectYellow()
{
	pManager->ReadyToChangeDrawColor = false;
	pManager->ReadyToChangeFillColor = false;
}
void SelectYellow::Undo()
{
}