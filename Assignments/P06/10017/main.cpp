///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            10017
// Title:            10017
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it finds the tower of hanoi for the
//  given numbers of moves.
//
/////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////
//      Function: void OutputPegs(vector<vector <int>> Pegs) 
//
// Description:
//      This function is used to ouput all of the pegs with there values
//  to a precise amount of spaces
//
/////////////////////////////////////////////////////////////////////////
void OutputPegs(vector<vector <int>> Pegs)
{
    cout << '\n';

    for (int i = 0; i < 3; i++)
    {
        cout << char(i + 65) << "=>";                   //prints a,b,or c

        if (!Pegs[i].empty())
        {
            cout << "   ";                              //three space if 
                                                        //not empty
            
            for (int j = 0; j < Pegs[i].size() - 1; j++)
            {
                cout << Pegs[i][j] << ' ';
            }
                
            cout << Pegs[i].back();                     //used so not an
                                                        //extra space
        }

        cout << '\n';
    }
}

/////////////////////////////////////////////////////////////////////////
//      Function: void solve(int & amountRan, int numRun, 
//  vector<vector <int>> & Pegs, int pegSize, int left,
//  int middle, int right) 
//
// Description:
//      This function is used to do all of the moves for the tower
//  of hanoi.
//
/////////////////////////////////////////////////////////////////////////
void solve(int & amountRan, int numRun, vector<vector <int>> & Pegs, 
int pegSize, int left, int middle, int right)
{
    if (amountRan == numRun)
    {
        return;                                     //breaks on end case
    }
        
    if (pegSize == 1)                               //final move
    {
        amountRan++;
        
        Pegs[right].push_back(Pegs[left].back());
        Pegs[left].pop_back();                      //moves pegs

        OutputPegs(Pegs);
    }
    else
    {
        solve(amountRan, numRun, Pegs, 
        pegSize - 1, left, right, middle);          //recursively causes
                                                    //peg moves
        
        if (amountRan == numRun)
        {
            return;                                 //breaks on end case
        }

        amountRan++;

        Pegs[right].push_back(Pegs[left].back());   //moves pegs
        Pegs[left].pop_back();
        
        OutputPegs(Pegs);

        solve(amountRan, numRun, Pegs, 
        pegSize - 1, middle, left, right);          //recursively causes
                                                    //peg moves
    }
}

int main()
{
    int numRun, pegSize, amountRan; 
    int probNum = 1;                                //used in recursion

    cin >> pegSize >> numRun;

    while (pegSize != 0)
    {
        vector<vector <int>> Pegs(3);               //holds the pegs 
                                                    //and values

        amountRan = 0;

        cout << "Problem #" << probNum;

        cout << '\n';                               //spacing

        for (int i = pegSize; i > 0; i--)
        {
            Pegs[0].push_back(i);                   //loads base peg
        }
            
        OutputPegs(Pegs);

        solve(amountRan, numRun, Pegs,pegSize, 0, 1, 2);    //solves
            
        cout << '\n';                               //spacing

        cin >> pegSize >> numRun;                   //used to check next
        probNum++;                                  //increases problem
    }

    return 0;
}