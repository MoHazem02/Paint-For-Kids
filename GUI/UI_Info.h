#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,     //Rectangle Icon
	ITM_CIRC,     //Circle Icon
	ITM_TRI,      //Triangle Icon
	ITM_SQ,       //Square Icon
	ITM_HEX,      //Hexagon Icon
	SLCTONE,      //Select One Icon
	CHNGCLR,      //Change Colors Icon
	FILCLR,       //Fill Shape Icon
	TRSH,         //Delete Shape Icon
	MOV,          //Move Shape Icon
	UNDO,         //Undo
	REDO,         //Redo
	CLEAR,        //Clear All Icon
	RCRD,         //Start Recording Icon
	STP,          //Stop Recording Icon
	PLY,          //Play Recording Icon
	SAVE,         //Save Button
	LOAD,         //Load Button
	ITM_EXIT,     //Exit Butoon

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PaletteColors
{
	black,
	yellow,
	orange,
	red,
	green,
	blue,
	ClrsCount
};


__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif