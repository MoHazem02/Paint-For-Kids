#pragma once
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& fout);
	virtual bool CheckSelectedPoint(Point P);
	virtual void MoveFigure(Point);
	virtual void Undo();
	Point virtual GetCenter();
};

