///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            11462
// Title:            11462
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it sorts the ages of a given set of 
//  people
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int SetSize, temp;

    cin >> SetSize;

    while(SetSize != 0)
    {
        vector<int> nums;

        for(int i = 0; i < SetSize; i++)
        {
            cin >> temp;
            nums.push_back(temp);
        }

        sort(nums.begin(), nums.end()); //sorts ages

        for(int i = 0; i < SetSize; i++)
        {
            cout << nums[i];

            if(i != SetSize - 1)
            {
                cout << ' ';//prints only enough spaces
            } 
        }

        cout << '\n';

        cin >> SetSize;
    }

    return 0;
}