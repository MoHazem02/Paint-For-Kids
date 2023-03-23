#pragma once
#include "Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertex1, Vertex2, Vertex3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& fout);
	virtual bool CheckSelectedPoint(Point);
	virtual void MoveFigure(Point);
	virtual void Undo();
	Point virtual GetCenter();
};

