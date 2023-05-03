/*
     B.S. Information Technology
     CSC 135 50
     Prof Earl
     Program 4
     project4.cpp
     Created 30 Oct 2021
     Due 5 Nov 2021
     Program will take user input on number of seats at a table and the
        price of each meal & calculate the subtotal, tax, tip, and total.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int getSeatNum();
float getSubTotal(int);
float getSubTotal(int);
float evalSalesTax(float, float);
float evalTip(int, float);
float evalTotal(float, float, float);
void printReceipt(int, float, float, float, float);

int main() 
{
    
    int tableNumber = 1;
    int seatNum;
    bool continueAsking = true;
    float subTotal;
    float seatPrice, salesTax, tip, total;
    const float taxRate = 0.07;

    do
    {
        //Set numbers not overwritten by user input to 0
        salesTax = 0;
        tip = 0;
        total = 0;

        seatNum = getSeatNum();

        //If seats are 0, trip a flag so the loop will not repeat and
        //the program will not continue
        if (seatNum == 0)
        {
            continueAsking = false;
        }
        else
        {
            subTotal = getSubTotal(seatNum);
            salesTax = evalSalesTax(taxRate, subTotal);
            tip = evalTip(seatNum, subTotal);
            total = evalTotal(subTotal, salesTax, tip);

            printReceipt(tableNumber, subTotal, salesTax, tip, total);

            tableNumber++;
        }
    }
    while (continueAsking == true);

    cout << "Thank you for your patronage." << endl << endl;

    return 0;
}

//Asks the user to input the number of seats at a table and
//returns the value to main
int getSeatNum()
{
    int seats;
    cout << "Please enter the number of seats at the table: ";
    cin >> seats;

    return seats;
}

//Get price for each table's seat and add it to subtotal
//and returns to main
//Looped for the number of seats entered by user
float getSubTotal(int seats)
{
    float subTotal = 0;
    float seatPrice = 0;

    cout << "Please enter the price for each seat's meal: ";

    for (int i = 1; i <= seats; i++)
    {
        cin >> seatPrice;
        subTotal = subTotal + seatPrice;
    }
    return subTotal;
}

//Take the subtotal and tax rate, evaluate the sales tax and return it to main
float evalSalesTax(float taxRate, float subTotal)
{
    float salesTax = 0;
    salesTax = subTotal * taxRate;

    return salesTax;
}

//Take subtotal and calculate the tip depending on the number of seats
float evalTip(int seats, float subTotal)
{
    float tip = 0;
    if (seats <= 6)
    {
        tip = subTotal * 0.2;
    }
    else
    {
        tip = subTotal * 0.25;
    }

    return tip;
}

//Take subtotal, sales tax, and the tip and sum it for the total
float evalTotal(float subTotal, float salesTax, float tip)
{
    float total = 0;
    total = subTotal + salesTax + tip;

    return total;
}

//Prints the formatted receipt for the table
void printReceipt(int tableNumber, float subTotal, float salesTax, float tip, float total)
{
    cout << endl << "Table " << tableNumber << ":" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Subtotal: $" << subTotal << endl;
    cout << "Tax: $" << salesTax << endl;
    cout << "Tip: $" << tip << endl;
    cout << "Total: $" << total << endl << endl;
}
