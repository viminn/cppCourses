/*
     B.S. Information Technology
     CSC 135 50
     Prof Earl
     Program 2
     project2.cpp
     Created 28 Sep 2021
     Due 1 Oct 2021
     Program will take user input of data subscription packages and
         print a bill based on the package chosen and gigabytes used.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Declaring Variables
    float gigabytesUsed, totalDue;
    char package;

    //Initializing variables through user input
    cout << "Please enter your purchased package:" << endl;
    cin >> package;

    //Filtering out invalid inputs immediately
    if (package == 'A' || package == 'B' || package == 'C')
    {
        switch (package)
        {
            case 'A':
                cout << "Please enter the total gigabytes used:" << endl;
                cin >> gigabytesUsed;
                //Determine if there is an additional charge based on data use
                if (gigabytesUsed > 15.0)
                {
                    totalDue = 30.95 + ((gigabytesUsed - 15.0) * 2);
                }
                else
                {
                    totalDue = 30.95;
                }
                break;

            case 'B':
                cout << "Please enter the total gigabytes used:" << endl;
                cin >> gigabytesUsed;

                if (gigabytesUsed > 25.0)
                {
                    totalDue = 40.95 + (gigabytesUsed - 25.0);
                }
                else
                {
                    totalDue = 40.95;
                }
                break;

            default:
                totalDue = 69.99;
                break;
        }
        if (package == 'A' || package == 'B')
        {
            cout << "Package " << package << endl << "Gigabytes Used: " << gigabytesUsed << endl;
            cout << fixed << showpoint << setprecision(2);
            cout << "Total Due: $" << totalDue << endl;
        }
        else
        {
            cout << "Package " << package << endl << "Unlimited Data" << endl;
            cout << "Total Due: $" << totalDue << endl;
        }
    }
    else
        cout << "You did not enter a valid package." << endl;
        return 0;
}
