#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"

class ColorImageClass
{
    private:
        ColorClass image[ROW_SIZE][COL_SIZE];
        void setImageToBlack();

    public:
        ColorImageClass();
        void initializeTo(ColorClass &inColor);
        bool addImageTo(ColorImageClass &rhsImg);
        bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);
        bool setColorAtLocation(RowColumnClass &inRowCol,ColorClass &inColor);
        bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
        void printImage();
};

#endif