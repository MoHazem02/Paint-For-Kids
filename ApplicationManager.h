#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\AddRectAction.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "CFigure.h"
#include "AddSquareAction.h"
#include "AddCircleAction.h"
#include "AddTriangleAction.h"
#include "AddHexagonAction.h"
#include "DeleteFigure.h"
#include "MoveFigure.h"
#include "ClearAllAction.h"
#include "ChangeFigColor.h"
#include "ChangeFillColor.h"
#include "SelectBlack.h"
#include "SelectBlue.h"
#include "SelectRed.h"
#include "SelectYellow.h"
#include "SelectGreen.h"
#include "SelectOrange.h"
#include "StartRecording.h"
#include "StopRecording.h"
#include "FillShape.h"
#include "ExitAction.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int FigCount2; //This is the length of the fig list, could include nulls, and won't be decremented
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	CFigure* RecordedList[20]; // List to keep track of drawn figs when recording
	Point MovedPts[5]; //array for points moved
	int Moved;

public:	
	bool IsRecording;
	int RecordCount;
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void UpdateRecordInterface() const;
	void SaveAll(ofstream& fout);
	void DeleteSelected();
	void DeleteFig(int);
	void DeleteAll();
	void UnselectAll();
	void LoadCircle(int, Point, int, GfxInfo);
	void LoadTriangle(int, Point, Point, Point, GfxInfo);
	void LoadSquare(int, Point, GfxInfo);
	void LoadRectangle(int, Point, Point, GfxInfo);
	void LoadHexagon(int, Point, GfxInfo);
	bool ReadyToChangeDrawColor; //verifies whether the user cllicked on change color before choosing the color
	bool ReadyToChangeFillColor;
	void ChangeSelectedDrawColor(color);
	void ChangeSelectedFillColor(color);
	void AddRecordedFigure(CFigure* pFig); //appends the drawn figure to RecordedList
	void Fill(); // sets the figures to filled
	void MoveSelected(Point P);

};

#endif