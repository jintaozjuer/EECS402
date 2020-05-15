#include <iostream>
using namespace std;

void printMenu();
double toThePower(double val, int power);
bool evaluateCubicFormula(double aCoeff, double bCoeff, double cCoeff, double dCoeff, double xValue, double &resultVal);
double approximateAreaWithRect(double aCoeff, double bCoeff, double cCoeff, double dCoeff, double startX, double endX, int numRects);

int main() 
{
    double aCoeff, bCoeff, cCoeff, dCoeff;
    double startX, endX, xValue;
    int choice, numRects;
    double area, correctAns, precision;
    const int MAX_ITERATION_NUM = 100;
    do
    {
        printMenu();
        cout << "YOUR CHOICE: " ;
        cin >> choice;
        if ((choice == 1) || (choice == 2))
        {
            cout << "Enter (a b c d) for function y = a*x^3 + b*x^2 + c*x + d: ";
            cin >> aCoeff >> bCoeff >> cCoeff >> dCoeff;
            cout << "Now enter x start and end values: ";
            cin >> startX >> endX;
        }
        if (choice == 1)
        {
            cout << "Enter the number of rectangles to use: ";
            cin >> numRects;
            area = approximateAreaWithRect(aCoeff, bCoeff, cCoeff, dCoeff, startX, endX, numRects);
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(6);
            cout << "Rectangle result is: " << area << endl;
        }
        if (choice == 2)
        {
            cout <<Enter correct answer: ";
            cin >> correctAns;
            cout << "Enter precision to reach: ";
            cin >> precision;

            numRects = 0;
            bool is_precise = false;
            do
            {
                numRects++; 
                area = approximateAreaWithRect(aCoeff, bCoeff, cCoeff, dCoeff, startX, endX, numRects);
                if (((area - correctAns) <= precision) && ((area - correctAns) >= -precision))
                {
                    is_precise = true;
                }          
            }while((!is_precise) && (numRects < MAX_ITERATION_NUM));
            if (is_precise)
            {
                cout << "Rectangles needed to reach precision: " << numRects << endl;
            }  
            else
            {
                cout << "Tried 100 rectangles without reaching precision" << endl;
            }        
        }        
    }while(choice != 3);
    
    cout << "Thanks for using this program" << endl;

    return 0; 
}


void printMenu()
{
    cout << "1. Approximate Integral Using Rectangles" << endl;
    cout << "2. Experiment With Rectangle Precision" << endl;
    cout << "3. Quit The Program" << endl;
}

double toThePower(double val, int power)
{
    double power_result = 1.0;
    for (int i = 0; i < power; i++)
    {
        power_result *= val;
    }
    return power_result;
}

bool evaluateCubicFormula(double aCoeff, double bCoeff, double cCoeff, double dCoeff, double xValue, double &resultVal)
{
    bool is_positive;   
    resultVal = aCoeff * toThePower(xValue, 3) + bCoeff * toThePower(xValue, 2) + cCoeff * xValue + dCoeff;
    if (resultVal < 0)
    {
        is_positive = false;
    }
    else 
    {
        is_positive = true;
    }
    return is_positive;
}

double approximateAreaWithRect(double aCoeff, double bCoeff, double cCoeff, double dCoeff, double startX, double endX, int numRects)
{
    double step = (endX - startX) / numRects;
    double  area = 0.0;
    for (int i = 0; i < numRects; i++)
    {
        double xValue = startX + (i + 0.5) * step;
        double resultVal;
        bool is_positive = evaluateCubicFormula(aCoeff, bCoeff, cCoeff, dCoeff, xValue, resultVal);
        if (is_positive)
        {
            area += resultVal * step;
        }
        else
        {
            area -= resultVal * step;
        }
    }
    return area;
}