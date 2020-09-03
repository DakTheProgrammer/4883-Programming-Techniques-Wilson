///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            11727
// Title:            UVA 11727
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and all it does is find the middle number 
//  in a set of 3 numbers used for cutting costs
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main()
{
    int nums[3];                    

    int t, temp;

    int c = 1;

    cin >> t;

    while(t != 0)
    {
        for(int i = 0; i < 3; i++)
        {
            cin >> nums[i];
        }

        if(nums[0] > nums [1])
        {
            temp = nums[1];                                 // swaps nums
            nums[1] = nums[0];
            nums[0] = temp;
        }

        if(nums[1] > nums[2])
        {
            temp = nums[2];                                 // swaps nums
            nums[2] = nums[1];
            nums[1] = temp;
            
            if(nums[0] > nums [1])
            {
                temp = nums[1];                             // swaps nums
                nums[1] = nums[0];
                nums[0] = temp;
            }
        }

        cout << "Case " << c << ": " << nums[1] << '\n';    // prints the middle
                                                            //of sorted array

        t--;
        c++;                                                // increases case 
                                                            //count
    }

    return 0;
}