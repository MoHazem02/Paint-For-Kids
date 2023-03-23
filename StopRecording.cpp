#include "StopRecording.h"


StopRecording::StopRecording(ApplicationManager* pApp) :Action(pApp)
{

}
void StopRecording::ReadActionParameters()
{
	//Get a Pointer to the  Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("stop recording");


	pOut->ClearStatusBar();

}

//Execute the action
void StopRecording::Execute()
{
	ReadActionParameters();
	pManager->DeleteAll();
	pManager->IsRecording = false;
}
void StopRecording::Undo()
{
}
