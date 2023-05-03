// Calculates the hypotenuse of a triangle

#include <iostream>
#include <cmath>

using namespace std;

double getSide(int);
double evaluateSide3(double, double);
void printSide3(double);

int main()
{
    double side1, side2, side3;

    side1 = getSide(1);
    side2 = getSide(2);

    side3 = evaluateSide3(side1, side2);

    //printSide3(side3);
    printSide3(evaluateSide3(side1, side2));
    
    return 0;
}

/*
    Function: getSide
    Description: 
    
*/
double getSide(int side)
{
    double tempSide;
    
    cout << "Enter the length of side " << side << ": ";
    cin >> tempSide;

    return tempSide;
}

/*
    Function: evaluateSide3
    Description: TBD
    Parameters:
        - double a: This is side1
        - double b: This is side2
    Returns: double - The value of side3
*/
double evaluateSide3(double a, double b)
{
    a = pow(a, 2);
    b = pow(b, 2);

    return sqrt(a+b);
}
/*
    Function: TBD
    Description: TBD
    Returns: N/A
*/
void printSide3(double c)
{
    cout << "Length of side 3 is: " << c << endl;
}
