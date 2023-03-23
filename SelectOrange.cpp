#include "SelectOrange.h"
SelectOrange::SelectOrange(ApplicationManager* pApp) : Action(pApp)
{
}
void SelectOrange::ReadActionParameters()
{
}
void SelectOrange::Execute()
{
	Output* pOut = pManager->GetOutput();
	color A = pOut->ConvertToColorObj("ORANGE");
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
SelectOrange::~SelectOrange()
{
	pManager->ReadyToChangeDrawColor = false;
	pManager->ReadyToChangeFillColor = false;

}
void SelectOrange::Undo()
{
}
