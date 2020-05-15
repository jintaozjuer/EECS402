#include "ColorClass.h"
#include "constants.h"
#include <iostream>
using namespace std;

ColorClass::ColorClass()
{
    redVal = MIN_RGB_VAL;
    greenVal = MIN_RGB_VAL;
    blueVal = MIN_RGB_VAL;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
    setTo(inRed, inGreen, inBlue);
}

bool ColorClass::clipVal(int inVal, int &val)
{
    bool isClipped = false;
    if (inVal > MAX_RGB_VAL)
    {
        isClipped = true;
        val = MAX_RGB_VAL;
    }
    else if (inVal < MIN_RGB_VAL)
    {
        isClipped = true;
        val = MIN_RGB_VAL;
    }
    else 
    {
        val = inVal;
    }
    return isClipped;
}

void ColorClass::setToBlack()
{
    redVal = MAX_RGB_VAL;
    greenVal = MAX_RGB_VAL;
    blueVal = MAX_RGB_VAL;
}

void ColorClass::setToRed()
{
    redVal = MAX_RGB_VAL;
    greenVal = MIN_RGB_VAL;
    blueVal = MIN_RGB_VAL;
}

void ColorClass::setToGreen()
{
    redVal = MIN_RGB_VAL;
    greenVal = MAX_RGB_VAL;
    blueVal = MIN_RGB_VAL;
}

void ColorClass::setToBlue()
{
    redVal = MIN_RGB_VAL;
    greenVal = MIN_RGB_VAL;
    blueVal = MAX_RGB_VAL;
}

void ColorClass::setToWhite()
{
    redVal = MIN_RGB_VAL;
    greenVal = MIN_RGB_VAL;
    blueVal = MIN_RGB_VAL;
}

bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
    bool isClipped = clipVal(inRed, redVal) || clipVal(inGreen, greenVal) || clipVal(inBlue, blueVal);
    return isClipped;
}

bool ColorClass::setTo(ColorClass &inColor)
{
    bool isClipped = setTo(inColor.redVal, inColor.greenVal, inColor.blueVal);
    return isClipped;
}

bool ColorClass::addColor(ColorClass &rhs)
{
    bool isClipped = setTo(rhs.redVal + redVal, rhs.greenVal + greenVal, rhs.blueVal + blueVal);
    return isClipped;
}

bool ColorClass::subtractColor(ColorClass &rhs)
{
    bool isClipped = setTo(redVal - rhs.redVal, greenVal - rhs.greenVal, blueVal - rhs.blueVal);
    return isClipped;
}

bool ColorClass::adjustBrightness(double adjFactor)
{
    bool isClipped = setTo(static_cast<int>(redVal * adjFactor),
                           static_cast<int>(greenVal * adjFactor),
                           static_cast<int>(blueVal * adjFactor));
    return isClipped;
}

void ColorClass::printComponentValues()
{
    cout << "R: " << redVal << "G: " << greenVal << "B: " << blueVal;
}

