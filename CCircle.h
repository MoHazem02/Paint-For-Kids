# pragma once
# include "Figures/CFigure.h"
#include "DeleteFigure.h"


class CCircle : public CFigure
{
private:
	Point Center;
	Point PointOnCircle;
	int Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& fout);
	virtual void Load(ifstream& fin);
	virtual bool CheckSelectedPoint(Point P);
	virtual void MoveFigure(Point);
	virtual void Undo();
	Point virtual GetCenter();

};

