#include "RowColumnClass.h"
#include "constants.h"
#include <iostream>
using namespace std;

RowColumnClass::RowColumnClass()
{
    rowInx = INITIAL_POS;
    colInx = INITIAL_POS;
}

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
    setRowCol(inRow,inCol);
}
void RowColumnClass::setRowCol(int inRow,int inCol)
{
    setRow(inRow);
    setCol(inCol);
}

void RowColumnClass::setRow(int inRow)
{
    rowInx = inRow;
}

void RowColumnClass::setCol(int inCol)
{
    colInx = inCol;
}

int RowColumnClass::getRow()
{
    return rowInx;
}

int RowColumnClass::getCol()
{
    return colInx;
}

void RowColumnClass::printRowCol()
{
    cout << "[" << rowInx << "," << colInx << "]";
}
