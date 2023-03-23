#pragma once
# include "Figures/CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& fout);
	virtual bool CheckSelectedPoint(Point P);
	virtual void MoveFigure(Point);
	virtual void Undo();
	Point virtual GetCenter();

};

