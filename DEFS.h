#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DrawSqre,		//Draw Square
	DrawTrng,       //Draw Triangle
	DrawCirc,		//Draw Circle  
	DrawHex,		//Draw Hexagon 
	SelectOne,		//Select One Shape
	ChangeColor,    //Change Shape Color
	FillColor,      //Fill Shape
	Delete,         //Delete Shape
	Drag,           //Move Shape
	Undo,         
	Redo,
	ClearAll,		//Deletes Everything
	Record,			//Start Recording
	StopRecord,		//Stops Recording (only displayed after Start recording has been clicked)
	PlayRecord,		//Plays Recording
	Save,			//Save Graph
	Load,			//Load Graph
	EXIT,			//Exit
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	_black,         
	_green,
	_blue,
	_red,
	_yellow,
	_orange,
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif