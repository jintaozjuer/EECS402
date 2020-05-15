#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

class RowColumnClass
{
    private:
        int rowInx;
        int colInx;

    public:
        RowColumnClass();
        RowColumnClass(int inRow, int inCol);

        void setRowCol(int inRow,int inCol);
        void setRow(int inRow);
        void setCol(int inCol);
        int getRow();
        int getCol();
        void printRowCol();
};

#endif