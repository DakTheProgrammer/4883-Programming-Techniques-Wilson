///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            11988
// Title:            UVA 11988
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it takes in a string of characters in
//  beiju text form and reorients it to be in plain text.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    string line;                                //line of text
    deque<string> ans;                          //double ended queue to translate

    while(getline(cin, line))
    {
        string temp, test;
        char ForB;                              //if need to go to front or end

        for(int i = 0; i < line.length(); i++)
        {
            if((line.at(i) == '[' 
            || line.at(i) == ']')
             && !temp.empty())
            {
                if(ForB == 'F')
                {
                    ans.push_front(temp);       //puts text in front
                    temp = "";
                }
                else
                {
                    ans.push_back(temp);        //puts text in back
                    temp = "";
                }
            }

            if(line.at(i) == '[')
            {
                ForB = 'F';                     //changes case
            }
            else if(line.at(i) == ']')
            {
                ForB = 'B';
            }
            else
            {
                test = line.at(i);
                temp.append(test);              //creates text
            }
        }

        if(ForB == 'F')
        {
           ans.push_front(temp);
        }
        else                                    //pushes last text
        {
            ans.push_back(temp);
        }

        while(!ans.empty())                     //displays answer
        {
            cout << ans.front();
            ans.pop_front();
        }
        
        cout << '\n';
    }
    return 0;
}