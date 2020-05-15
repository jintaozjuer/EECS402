#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

class ColorClass
{
    private:
        int redVal;
        int greenVal;
        int blueVal;
        bool clipVal(int inVal, int &val);


    public:
        ColorClass();
        ColorClass(int inRed, int inGreen, int inBlue);

        void setToBlack();
        void setToRed();
        void setToGreen();
        void setToBlue();
        void setToWhite();
        bool setTo(int inRed, int inGreen, int inBlue);
        bool setTo(ColorClass &inColor);
        bool addColor(ColorClass &rhs);
        bool subtractColor(ColorClass &rhs);
        bool adjustBrightness(double adjFactor);
        void printComponentValues();
};
#endif