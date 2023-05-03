/*
    B.S. Information Technology
    CSC 135 50
    Prof Earl
    Program 6
    project6.cpp
    Created 2 Dec
    Due 10 Dec
    Program will grade a 20 question multiple choice quiz for an 
        unknown number of students and output statistics on who passed
        and what questions were missed.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const char ansKey[20] = {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D',
    'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'};
const int arraySize = 20;

void scoreStudent(char[], bool[], string&);
void calcScore(bool[], string&);

int main()
{
    ifstream ifs;
    char studentAns[20];
    bool isCorrect[20];
    string QsIncorrect = "";
    int totalMissed = 0;

    ifs.open("driving.dat");
    while (!ifs.eof())
    {
        for (int i = 0; i < arraySize; i++)
        {
             ifs >> studentAns[i];
        }
        scoreStudent(studentAns, isCorrect, QsIncorrect);
    }
    return 0;
}

/*
Sets the bool array true or false depending on if the student's answer was correct
or not. Takes the student answer array, the bool array, and the string of missed
questions as input and passes the bool array of answers and the missed questions string to calcScore
Builds a string of the number of each question missed
*/
void scoreStudent(char studentAns[], bool isCorrect[], string& QsIncorrect)
{
    for (int i = 0; i < arraySize; i++)
    {
        isCorrect[i] = (studentAns[i] == ansKey[i]);
        if (!isCorrect[i])
        {
            QsIncorrect += to_string(i+1) + " ";
        }
    }
    calcScore(isCorrect, QsIncorrect);
}

/*
calcScore
Calculates the total number of missed questions and prints out the student report
Takes the bool array and the string of missed questions from scoreStudent as input
and outputs the table of the student's result
*/
void calcScore(bool isCorrect[], string& QsIncorrect)
{
    int totalMissed = 0;
    string grade = "";

    for (int i = 0; i < arraySize; i++)
    {
        totalMissed += (!isCorrect[i]);
    }
    if (totalMissed <= 5)
    {
        grade = "Pass";
    }
    else
    {
        grade = "Fail";
    }
    cout << "# Correct" << "  # Incorrect" << "  Pass/Fail" << "   Missed Qs Number" << endl;
    cout << "  " << (20 - totalMissed) << "          " << totalMissed << "          "
        << grade << "          " << QsIncorrect << endl;

    QsIncorrect = "";
}
