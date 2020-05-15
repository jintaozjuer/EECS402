#include "ColorImageClass.h"
#include <iostream>
using namespace std;

void ColorImageClass::setImageToBlack()
{
    for(int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COL_SIZE; j++)
        {
            image[i][j].setToBlack();
        }
    }

}

ColorImageClass::ColorImageClass()
{
    setImageToBlack();
}

void ColorImageClass::initializeTo(ColorClass &inColor)
{
    for(int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COL_SIZE; j++)
        {
            image[i][j].setTo(inColor);
        }
    }
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
    bool isClipped = false;
    for(int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COL_SIZE; j++)
        {
            if (image[i][j].addColor(rhsImg[i][j]))
            {
                isClipped = true;
            }
        }
    }
    return isClipped;
}

bool ColorImageClass::addImages(int numImgsToAdd, ColorImageClass imagesToAdd[])
{
    bool isClipped = false;
    setImageToBlack();
    for(int i = 0; i < numImgsToAdd; i++)
    {
        if(addImageTo(imagesToAdd[i]))
        {
            isClipped = true;
        }
    }
    return isClipped;
}

bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,ColorClass &inColor)
{
    bool isValidLoc = false;
    int rowInx = inRowCol.getRow();
    int colInx = inRowCol.getCol();
    if (rowInx < ROW_SIZE && rowInx >= 0 && colInx < COL_SIZE && colInx >= 0)
    {
        image[rowInx][colInx].setTo(inColor);
        isValidLoc = true;
    }
    
    return isValidLoc;
}

bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor)
{
    bool isValidLoc = false;
    int rowInx = inRowCol.getRow();
    int colInx = inRowCol.getCol();
    if (rowInx < ROW_SIZE && rowInx >= 0 && colInx < COL_SIZE && colInx >= 0)
    {
        outColor.setTo(image[rowInx][colInx]);
        isValidLoc = true;
    }
    
    return isValidLoc;
}

void ColorImageClass::printImage()
{
    cout << "Printing entire test image:" << endl;
    for(int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COL_SIZE; j++)
        {
            image[i][j].printComponentValues();
            if (j == COL_SIZE - 1)
            {
                cout << endl;
            }
            else
            {
                cout << "--";
            }
        }
    }

}