/*
    B.S. Information Technology
    CSC 135 50
    Prof Earl
    Program 3
    project3.cpp
    Created 14 Oct 2021
    Due 22 Oct 2021
    Program will take user input on square footage to be washed and the 
        price of bleach and output the square footage to be washed, the
        cost of the bleach used, and the total cost including labor.
*/

#include <iostream>
#include <iomanip>

using namespace std;

float getSquareFeet();
float getBleachPerGal();
float evalBleachCost(float, float);
float evalLaborCost(float);
float evalTotalCost(float, float);
void printTotalCost(float, float, float, float, float);

int main() 
{
    float squareFeet, bleachCostPerGal, bleachCost, laborCost, totalCost;
    
    squareFeet = getSquareFeet();
    bleachCostPerGal = getBleachPerGal();
    if (bleachCostPerGal < 3.0)
    {
        cout << "An invalid price per gallon of less than $3 was entered." << endl;
        return 0;
    }
    bleachCost = evalBleachCost(squareFeet, bleachCostPerGal);
    laborCost = evalLaborCost(squareFeet);
    totalCost = evalTotalCost(bleachCost, laborCost);
    printTotalCost(squareFeet, bleachCostPerGal, bleachCost, laborCost, totalCost);

    return 0;
}

//Prompt the user to input the square footage to be washed and returns value to main
float getSquareFeet()
{
    float squareFootage = 0.0;
    cout << "Please enter the square footage to be washed: ";
    cin >> squareFootage;

    return squareFootage;
}

//Prompt user for cost of bleach per gallon and returns value to main
float getBleachPerGal()
{
    float costPerGal = 0.0;
    cout << "Please enter the cost of bleach per gallon: ";
    cin >> costPerGal;

    return costPerGal;
}

//Take the cost of bleach per gallon and the square footage to evaluate the amount of bleach used
//and cost of that bleach
float evalBleachCost(float area, float cost)
{
    float totalBleachCost;
    totalBleachCost = (area / 60) * cost;

    return totalBleachCost;
}

//Divide square footage by 20 to get hours of labor, then multiply by the hourly rate 40 
//to get labor cost and return value to main
float evalLaborCost(float area)
{
    float laborCost;
    laborCost = (area / 20) * 40;

    return laborCost;
}

//Calculate the total cost with bleach cost and labor cost
float evalTotalCost(float bleach, float labor)
{
    float totalCost = bleach + labor;
    return totalCost;
}

//Print every component value and the total cost of the project
void printTotalCost(float area, float bleachPerGal, float bleachCost, float laborCost, float totalCost)
{
    cout << area << " square feet will be washed." << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Bleach costs $" << bleachPerGal << " per gallon." << endl;
    cout << "The total cost of bleach will be $" << bleachCost << endl;
    cout << "The total cost of labor will be $" << laborCost << endl;
    cout << "The total cost of the project will be $" << totalCost << endl;
}
