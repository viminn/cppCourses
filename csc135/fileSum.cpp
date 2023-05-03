// A file to take numbers from a given file and returns a sum of all the numbers

#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    ifstream ifs;
    string filename;
    int number;
    int sum = 0;

    cout << "Enter the name of the file with your numbers: ";
    cin >> filename;

    //ifs.open accepts: c string
    ifs.open(filename);

    //part of ifs stream. if ifstream mapped to fstream, 
    //then fstream.fail()
    if(ifs.fail())
    {
        cout << "Error, couldn't open file." << endl;
        return 0;
    }
    
    //ifs is the loop control variable since it returns true/false
    while(ifs >> number)
    {
        sum = sum + number;
        //or sum += number;
    }

    cout << "Sum of file: " << sum << endl;

    return 0;
}
