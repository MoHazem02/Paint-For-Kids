#include "StartRecording.h"

StartRecording::StartRecording(ApplicationManager* pApp) :Action(pApp)
{

}
void StartRecording::ReadActionParameters()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Started Recording: ");

}

//Execute the action
void StartRecording::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->IsRecording = true;
	pManager->RecordCount = 0;
	pManager->DeleteAll();

}
void StartRecording::Undo()
{
}
