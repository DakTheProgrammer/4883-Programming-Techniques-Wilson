///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            12403
// Title:            UVA 12403
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it takes a series of donations and 
//  adds them up until it needs to be reported which causes the total accrued 
//  to be printed.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, k, num;
    int total = 0;                      // total donations

    string DonOrRep;

    cin >> t;

    while(t != 0)
    {
        cin >> DonOrRep;

        if(DonOrRep == "donate")        // checks if the total needs to increase
                                        //or be printed
        {
            cin >> num;
            total += num;
        }
        else
        {
            cout << total << '\n';
        }
        

        t--;
    }

    return 0;
}