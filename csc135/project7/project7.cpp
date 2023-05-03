/*
    B.S. Information Technology
    CSC 135 50
    Prof Earl
    Program 7
    project7.cpp
    Created 16 Dec
    Due 17 Dec
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

void scoreStudent(char[][20], bool[][20], int, string&);
void calcScore(bool[][20], int, string&);

int main()
{
    ifstream ifs;

    string QsIncorrect = "";
    int totalMissed = 0;
    //Number of students and placeholder string
    int numOfStud = -1;
    string line = "";

    ifs.open("driving.dat");

    //Read through file to get line number to initialize array
    while (!ifs.eof())
    {
        getline(ifs, line);
        numOfStud++;
        line = "";
    }
    //Close and reopen file to reset pointer
    ifs.close();

    char studentAns[numOfStud][arraySize];
    bool isCorrect[numOfStud][arraySize];

    ifs.open("driving.dat");

    for (int i = 0; i < numOfStud; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            ifs >> studentAns[i][j];
        }
    }
    scoreStudent(studentAns, isCorrect, numOfStud, QsIncorrect);

    ifs.close();
    return 0;
}

/*
scoreStudent
Sets the bool array true or false depending on if the student's answer was correct
or not. Takes the student answer array, the bool array, and the string of missed
questions as input and passes the bool array of answers and the missed questions string to calcScore
Builds a string of the number of each question missed
*/
void scoreStudent(char studentAns[][20], bool isCorrect[][20], int iNumOfStud, string& QsIncorrect)
{
    for (int i = 0; i < iNumOfStud; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            isCorrect[i][j] = (studentAns[i][j] == ansKey[j]);
        }
    }
    calcScore(isCorrect, iNumOfStud, QsIncorrect);
}

/*
calcScore
Calculates the total number of missed questions and prints out the student report
Takes the bool array and the string of missed questions from scoreStudent as input
and outputs the table of the student's result
*/
void calcScore(bool isCorrect[][20], int iNumOfStudent, string& QsIncorrect)
{
    int missedCount = 0;
    string grade = "";
    cout << "# Correct" << "  # Incorrect" << "  Pass/Fail" << "   Missed Qs Number" << endl;
    for (int i = 0; i < iNumOfStudent; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            missedCount += (!isCorrect[i][j]);

            if (!isCorrect[i][j])
            {
                QsIncorrect += to_string(j+1) + " ";
            }
        }
        if (missedCount <= 5)
        {
            grade = "Pass";
        }
        else
        {
            grade = "Fail";
        }

        cout << "  " << (20 - missedCount) << "          " << missedCount << "          "
            << grade << "          " << QsIncorrect << endl;

        QsIncorrect = "";
        missedCount = 0;
    }
}
