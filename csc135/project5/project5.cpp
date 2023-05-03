/*
    B.S. Information Technology
    CSC 135 50
    Prof Earl
    Program 5
    project5.cpp
    Created 5 Nov 2021
    Due 12 Nov 2021
    Program will read data from a file on the seat number and price per
        seat of tables. Program will then calculate and print the bill
        for every table in the file. Program will end if an incorrect 
        filename is entered or the end of file is reached. Reference
        parameters are used.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Function prototypes
void openFile(ifstream&);
void readFile(ifstream&, int&, float&, float&, float&, float&);
//Function below benefits most from reference param
//Other variables as reference for sake of program
void evalTaxTipTotal(int&, float&, float&, float&, float&);
void printBill(float&, float&, float&, float&, int);

int main() 
{
    //Variable declaration
    ifstream ifs;
    int seatNum;
    float subTotal, tax, tip, total;

    openFile(ifs);
    readFile(ifs, seatNum, subTotal, tax, tip, total);

    return 0;
}

/*
openFile
User inputs name of file and opens it. If file cannot be opened, prints
    an error and exits the program
ifstream& file: ifs from main to open the file
string filename: placeholder string for user to enter filname
*/
void openFile(ifstream& file)
{
    string filename;

    cout << "Enter the name of the file: ";
    cin >> filename;

    file.open(filename);
    if (!file.is_open())
    {
        cout << "Error: File could not be opened." << endl;
        exit(0);
    }
}

/*
readFile
reads user's file and passes data into bill calculation and calls the
    bill to be printed. loops for every table in the file
ifstream& file: same as openFile
int tableNum: table number read from file and passes to printBill
    and increments
int& seats: seats at a table input from file
float& subTotal: table subtotal passed to eval function
float& tip: table's tip passed to eval function
float& tax: table's tax passed to eval function
float& total: table's total passed to eval function
*/
void readFile(ifstream& file, int& seats, float& subTotal, float& tip, float& tax, float& total)
{
    float seatPrice;
    int tableNum = 0;
    while(file >> seats)
    {
        tableNum++;
        for(int i = 1; i <= seats; i++)
        {
            file >> seatPrice;
            subTotal = subTotal + seatPrice;
        }
        evalTaxTipTotal(seats, subTotal, tax, tip, total);
        printBill(subTotal, tax, tip, total, tableNum);
        subTotal = 0;
    }

}

/*
evalTaxTipTotal
Takes the subtotal from readFile and calculates the rest of the bill
int& seats: file input to calculate tip
float& subTotal, tax, tip, total: take advantage of reference param,
    all passed to printBill
*/
void evalTaxTipTotal(int& seats, float& subTotal, float& tax, float& tip, float& total)
{
    tax = subTotal * 0.07;
    if (seats <=6)
    {
        tip = subTotal * 0.2;
    }
    else
    {
        tip = subTotal * 0.25;
    }
    total = subTotal + tip + tax;
}

/*
printBill
Takes the data from the file and calulated data to output a bill for
    each table
int tableNum: outputs to track table number from the file
float& subTotal, tax, tip, total: output components of the table's bill
*/
void printBill(float& subTotal, float& tax, float& tip, float& total, int tableNum)
{
    if (tableNum == 1)
    {
        cout << endl;
    }
    cout << "Table " << tableNum << ":" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Subtotal: $" << subTotal << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Tip: $" << tip << endl;
    cout << "Total: $" << total << endl << endl;
}
