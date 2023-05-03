#include <iostream>

using namespace std;

int main() {

    //Variables
    double tempIn;
    double tempOut;
    char tempUnit;

    //User enters Input Temp
    cout << "Enter a temperature:" << endl;
    cin >> tempIn;

    //User inputs temperature unit
    cout << "What is the temperature unit?" << endl;
    cin >> tempUnit;

    /*
    //Check if user inputted correct unit

    if (tempUnit != 'C' && tempUnit != 'c'
        && tempUnit != 'F' && tempUnit != 'f')
    {
        cout << "You did not enter a valid unit." << endl;
        return 0;
    }
    */

    //Switch to calculation given by tempUnit
    switch (tempUnit)
    {
        case 'c':
        case 'C':
            tempOut = (tempIn * (9.0/5.0)) + 32;
            tempUnit = 'F';
            break;
        case 'f':
        case 'F':
            tempOut = (tempIn + 32) * (5.0/9.0);
            tempUnit = 'C';
            break;
        default:
            cout << "You didn't enter a valid unit." << endl;
            return 0;
    }

    /*
    //Convert F to C when tempUnit is F
    if (tempUnit == 'F' || tempUnit == 'f')
    {
        tempOut = (tempIn - 32) * (5.0/9.0);
        tempUnit = 'C';
    }
    //Convert C to F otherwise
    else
    {
        tempOut = (tempIn * (9.0/5.0)) + 32;
        tempUnit = 'F';
    }
    */
    
    //Output
    cout << "The converted temp is: " << tempOut << " " << tempUnit << endl;
    return 0;
}
