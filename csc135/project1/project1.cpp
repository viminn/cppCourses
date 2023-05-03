/* 
    B.S. Information Technology
    CSC 135 050
    Prof Earl
    Program 1
    project1.cpp
    Created 8 Sept 2021
    Due 17 Sept 2021
    Program will calculate and print a tax report based on
         user-inputted values of money collected.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declaring variables
    float totalMoney, totalTax, productSales, countySales, stateSales;
    int year;
    string month;
    
    //Initializing variables through user input
    cout << "Enter the month:\n";
    cin >> month;

    cout << "Enter the year:\n";
    cin >> year;
    
    cout << "Enter the total amount collected:\n";
    cin >> totalMoney;

    //Evaluate taxes
    productSales = totalMoney / 1.06;
    totalTax = totalMoney - productSales;
    //County sales tax (2%) is one third of total sales tax (6%)
    countySales = totalTax / 3;
    //State sales tax is 2 thirds of total tax, or twice the value of county tax
    stateSales = countySales * 2;

    //Return tax report
    cout << "\nMonth: " << month << endl;
    cout << "Year: " << year << endl;
    cout << "-----------" << endl;
    
    //Formatting values of money to 2 decimals
    cout << fixed << showpoint << setprecision(2);
    //Printing calculated taxes
    cout << "Total Collected: $ " << totalMoney << endl;
    cout << "Total Product Sales: $ " << productSales << endl;
    cout << "County Sales Tax: $ " << countySales << endl;
    cout << "State Sales Tax: $ " << stateSales << endl;
    cout << "Total Sales Tax: $ " << totalTax << endl << endl;

    return 0;
}
