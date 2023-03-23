#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu, called when clicked on PLAYMODE
	void CreateStatusBar() const;	//create the status bar
	//void DisplayColors() const;     //Shows the 6 Colors Palette, called when clicked on CHNGCLR,FILCLR
	void Pick_Hide_Modes() const;   //Shows types for Pick And Hide




	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawSqre(Point P, GfxInfo SqreGfxInfo, bool selected = false) const;
	void DrawTrng(Point P1, Point P2, Point P3, GfxInfo TrngGfxInfo, bool selected = false) const;
	void Drawcrc(Point P1, Point P2, GfxInfo CrcGfxInfo, bool selected) const;    // Draw a circle
	void DrawHex(Point P1, int v, GfxInfo HexGfxInfo, bool selected) const; // Draw a hexagon

	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	string ConvertToColor(color); //Since the color object has three values as rgb and should be displayed as strings I have to map them
	color ConvertToColorObj(string); //Since the color object has three values as rgb and should be displayed as strings I have to map them

	~Output();
};

#endif