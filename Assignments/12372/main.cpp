///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            12372
// Title:            UVA 12372
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it checks and sees if object with a 
//  length width and hight can fit into a 20x20x20 suitcase.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main()
{
    int t, l, w, h;

    int c = 1;                                  // case count

    cin >> t;

    while(t != 0)
    {
        cin >> l >> w >> h;

        if(l > 20 || w > 20 || h > 20)          // checks if the object will fit
        {
            cout << "Case " << c << ": bad\n"; 
        }
        else                                    // if doesn't fit
        {
            cout << "Case " << c << ": good\n";
        }

        c++;
        t--;
    }

    return 0;
}