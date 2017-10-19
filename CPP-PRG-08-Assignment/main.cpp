//
//  main.cpp
//  CPP-PRG-08-Assignment
//
//  Created by Keith Smith on 10/19/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A Contest Scoring Program:
//
//  Your company has been selected to implement a contest scoring program for the upcoming Winter Olympics. Each contestant in the Olympics will compete in five (5) competitions.  There will be five (5) contestants. Each competition will be scored on a value of 0 through 10 with 10 being the best and 0 being the worst.
//  Your job as a programmer is to develop a program to collect (input) the scores for each of the 5 contestants for each of the 5 competitions. (Hint a 2 dimensional array => 5 X 5)
//  Your program will determine the highest score for that completion and display the number of the winner (1 through 5). (Hint: find the largest value in each column). In addition, your program should total up the total scores for the contestants and award 1st place for the overall winner. (Hint: Sum up each row and find the largest value)
//  Your main program will prompt for each contest and allow the entry of the scores for each contestant. For example:
//  Contest #1
//  7.5 9.3 8.5 7.2 10.0
//  Contest #2
//  8.1 7.8 9.2 10.0 7.7 8.5
//  Contest #3
//  ………….
//  Contest #4
//  ………….
//  Contest #5
//  ………….
//  The winner for Contest #1 is number 5
//  The winner for Contest #2 is number 3
//  The winner ……
//  The winner ……
//  The winner ……
//  The 1st place winner is number XX

#include <iostream>
#include <iomanip>

using namespace std;

// Declare global constant values for array columns and rows
const int INT_COLS = 5;
const int INT_ROWS = 5;

// Called 1 time. Loops through all array elements
// and gets a score for each element. Data is validated here.
void enterContestantScores(float [][INT_ROWS]);
// Called 5 times total, calculates highest score and winning index
// and returns the two values to main by modifying reference variables
void returnWinnerData(float [][INT_ROWS], int [], int &, float &, const int);
// Called one time to determine who won the competition
void returnWinnerData(int [], int &, int &);

int main()
{
    // Declare float array to hold all contestant scores
    float fltArrContestantScores [INT_COLS][INT_ROWS];
    int intArrContestantWins [INT_COLS] = { 0, 0, 0, 0, 0 };
    
    // Declare variables to hold index and scores
    // of the winning contestants
    // Winner/Score for contest #1
    int intContestWinnerIndex1;
    float fltContestWinnerScore1;
    // Winner/Score for contest #2
    int intContestWinnerIndex2;
    float fltContestWinnerScore2;
    // Winner/Score for contest #3
    int intContestWinnerIndex3;
    float fltContestWinnerScore3;
    // Winner/Score for contest #4
    int intContestWinnerIndex4;
    float fltContestWinnerScore4;
    // Winner/Score for contest #5
    int intContestWinnerIndex5;
    float fltContestWinnerScore5;
    
    // Declare variables to hold winning contestant index
    // and winning contestant's total number of wins
    int intWinnerIndex;
    int intWinnerWins;
    
    // Declare constants for contest numbers to pass
    // to function returnWinnerData()
    const int INT_CONTEST_0 = 0;
    const int INT_CONTEST_1 = 1;
    const int INT_CONTEST_2 = 2;
    const int INT_CONTEST_3 = 3;
    const int INT_CONTEST_4 = 4;
    
    // Set precision on outputs for single decimal point
    // per traditional contest scoring guidelines
    cout << setprecision(1) << fixed << showpoint;
    
    // Fill in array with user inputs
    enterContestantScores(fltArrContestantScores);
    
    // Call returnWinnerData() 5 times to get the winners of
    // each of the 5 contests
    returnWinnerData(fltArrContestantScores, intArrContestantWins, intContestWinnerIndex1, fltContestWinnerScore1, INT_CONTEST_0);
    returnWinnerData(fltArrContestantScores, intArrContestantWins, intContestWinnerIndex2, fltContestWinnerScore2, INT_CONTEST_1);
    returnWinnerData(fltArrContestantScores, intArrContestantWins, intContestWinnerIndex3, fltContestWinnerScore3, INT_CONTEST_2);
    returnWinnerData(fltArrContestantScores, intArrContestantWins, intContestWinnerIndex4, fltContestWinnerScore4, INT_CONTEST_3);
    returnWinnerData(fltArrContestantScores, intArrContestantWins, intContestWinnerIndex5, fltContestWinnerScore5, INT_CONTEST_4);
    
    // Called to determine overall winner by counting number of wins
    // there is a tie if the returned value == 1, will set up
    // if/else if/else statement in main to account for this returned value
    returnWinnerData(intArrContestantWins, intWinnerIndex, intWinnerWins);
    
    // Output results to the console. Could have used global
    // variables and called a function to output the message
    // but I didn't want to use global variables for this purpose
    
    // Display winning contestant number and score for contest #1
    cout << "Contest #1: Winner: Contestant #" << intContestWinnerIndex1 + 1;
    cout << ",\nwinning score: " << fltContestWinnerScore1 << endl;
    
    // Display winning contestant number and score for contest #1
    cout << "Contest #2, Winner: Contestant #" << intContestWinnerIndex2 + 1;
    cout << ",\nwith a winning score of: " << fltContestWinnerScore2 << endl;
    
    // Display winning contestant number and score for contest #1
    cout << "Contest #3, Winner: Contestant #" << intContestWinnerIndex3 + 1;
    cout << ",\nwith a winning score of: " << fltContestWinnerScore3 << endl;
    
    // Display winning contestant number and score for contest #1
    cout << "Contest #4, Winner: Contestant #" << intContestWinnerIndex4 + 1;
    cout << ",\nwith a winning score of: " << fltContestWinnerScore4 << endl;
    
    // Display winning contestant number and score for contest #1
    cout << "Contest #5, Winner: Contestant #" << intContestWinnerIndex5 + 1;
    cout << ",\nwith a winning score of: " << fltContestWinnerScore5 << endl;
    
    // If intWinnerWins == 1, then that was the highest number of wins that was
    // detected in returnWinnerData and that means all 5 contestants had 1 win each
    // therefore it's a tie and we need a special case to address this outcome
    if(intWinnerWins == 1)
    {
        cout << "There was a tie between everyoneso there\n";
        cout << "was no first place winner overall.\n";
    }
    // This is the standard outcome, one contestant got at least 1 more
    // wins than all the other contestants so we get the index value
    // and the array value at that index to display to the user
    else if(intWinnerWins != 1)
    {
        cout << "The first place winner overall is\n";
        cout << "Contestant #" << intWinnerIndex + 1 << " with ";
        cout << intWinnerWins << " total wins.\n";
    }
    // Throw an error message here detailing where the process went wrong
    else
    {
        cout << "ERROR CALCULATING OVERALL WINNER\n";
    }
    
    // Exit program
    return 0;
}

// Used to get user inputs on all contests and all contestant's scores
void enterContestantScores(float fltArr[][INT_ROWS])
{
    // Declare temporary float value to hold user input
    float fltTempScore;
    
    // Loop through each column...
    for(int i = 0 ; i < INT_COLS ; i++)
    {
        // ...and then loop through each row
        cout << "Please enter the scores for Contest #" << i + 1 << ".\n";
        for(int j = 0 ; j < INT_ROWS ; j++)
        {
            // Prompt user for contestant number's score
            // and validate the input to ensure it's between 0.0 and 10.0
            cout << "Please enter the score for Contestant #" << j + 1 << ": ";
            cin >> fltTempScore;
            // Validate data here, !fltTempScore prevents non-float values
            // from being entered. Otherwise entering characters breaks
            // the program and skips to the end of this function without
            // filling out the array
            while(!fltTempScore || fltTempScore < 0.0f || fltTempScore > 10.0f)
            {
                // !fltTempScore prevents a value of 0.0 from being entered
                // this if statement catches the exception and breaks out of
                // data validation if it detects a score of 0.0
                if(fltTempScore == 0.0f)
                {
                    break;
                }
                cout << "Please enter a score between 0.0 and 10.0: ";
                cin.clear();
                cin.ignore();
                cin >> fltTempScore;
            }
            
            // Set array element[current col][current row] to validated score
            fltArr[i][j] = fltTempScore;
        }
    }
}

// Called once per contest to select highest score in that row (cols then rows in this array).
// Get fixed index from function call in main.
void returnWinnerData(float fltArr[][INT_ROWS], int intArr[], int &refIndex, float &refScore, const int index)
{
    // Declare temp float score holder for comparison
    // Initialize at 0
    float fltTempHighScore = 0.0f;
    // Declare temp index holder to keep track of highest
    // scores position in the array to return to main (via reference)
    int intTempHighScoreIndex = 0;
    
    // Loop through this column(index)'s values (rows)
    // and keep track of largest value and that value's subscript
    for(int i = 0 ; i < INT_ROWS ; i++)
    {
        if(fltArr[index][i] > fltTempHighScore)
        {
            fltTempHighScore = fltArr[index][i];
            intTempHighScoreIndex = i;
        }
    }
    // Set refScore and refIndex to highest value found and its subscript.
    // Return these to main by modifying their reference positions
    // and increment the 1st place winner's total win count in intArr
    refScore = fltTempHighScore;
    refIndex = intTempHighScoreIndex;
    intArr[intTempHighScoreIndex]++;
}

void returnWinnerData(int intArr[], int &refIndex, int &refWins)
{
    // Declare and initialize two temporary counter variables
    // for the value at array index i and for storing i
    int intTempIndex = 0;
    int intTempCounter = 0;
    
    // Loop through the winner's tally array
    for(int i = 0 ; i < INT_COLS ; i++)
    {
        if(intArr[i] > intTempCounter)
        {
            // If intArr[i] is of greater value than the temporary counter's value
            // set the counter equal to the array value and set the temp index's
            // value equal to i
            intTempIndex = i;
            intTempCounter = intArr[i];
        }
    }
    
    // Set reference variables equal to temporary
    // calculated values
    refIndex = intTempIndex;
    refWins = intTempCounter;
}
