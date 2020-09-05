///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            673
// Title:            UVA 673
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it takes in a set of parentheses and 
//  brackets and uses a stack to see if it is balanced 
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//                    Function:string Solve(string Prob)
//
// Description:
//      This function takes in a string of parentheses and brackets and finds if
//  it is balanced
//
/////////////////////////////////////////////////////////////////////////////////
string Solve(string Prob)
{
    stack<char> Matcher;

    for(int i = 0; i < Prob.length(); i++)
    {
        if(Prob.at(i) == '(' || Prob.at(i) == '[')              //places in stack
                                                                //if it is left 
                                                                //sided
        {
            Matcher.push(Prob.at(i));
        }
        else
        {
            if(Matcher.empty())                                 //breaks if 
                                                                //starts with 
                                                                //right sided
            {
                return "No\n";
            }
            
            if(Prob.at(i) == ']' && Matcher.top() != '[')
            {
                return "No\n";
            }
            else if(Prob.at(i) == ')' && Matcher.top() != '(')  //both check 
                                                                //if there is 
                                                                //a matching 
                                                                //one on top of
                                                                //the stack
            {
                return "No\n";
            }

            Matcher.pop();                                      //pops to check 
                                                                //next one
        }
    }

    if(!Matcher.empty())                                        //breaks if the 
                                                                //problem doesn't 
                                                                //solve all
    {
        return "No\n";
    }

    return "Yes\n";                                             //if works breaks 
                                                                //with yes
}

int main()
{
    int t;

    cin >> t;                                                   //times to loop

    string blank, Prob;

    getline(cin, blank);                                        //blank line

    for(int i = 0; i < t; i++)
    {
        getline(cin, Prob);                                     //gets line of 
                                                                //input

        cout << Solve(Prob);
    }
}