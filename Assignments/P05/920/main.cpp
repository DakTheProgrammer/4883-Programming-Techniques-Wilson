///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            920
// Title:            920
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it finds the summation of all of the
// sunny sides of a mountains in a range
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

/////////////////////////////////////////////////////////////////////////
//      Function:bool DecendX(pair<int,int> First, pair<int,int> Second) 
//
// Description:
//      This function is used as a condition for the sort algorithm that
//  sorts pairs in there decending firsts order
//
/////////////////////////////////////////////////////////////////////////
bool DecendX(pair<int,int> First, pair<int,int> Second)
{
    return Second.first < First.first;
}

int main()
{
    int NumCases, temp1, temp2;
    double q, p;                                                        //used for 
                                                                        //perameters
                                                                        //of 
                                                                        //euclidian 
                                                                        //distance                                     

    cin >> NumCases;

    while(NumCases != 0)
    {
        int NumPairs;
        int Highest = 0;
        double Distance = 0;

        cin >> NumPairs;

        vector<pair<int,int>> XandY(NumPairs);                          //pair of 
                                                                        //x and y

        for(int i = 0; i < NumPairs; i++)
        { 
            cin >> temp1;
            cin >> temp2;

            XandY[i].first = temp1;
            XandY[i].second = temp2; 
        }

        sort(XandY.begin(), XandY.end(), DecendX);

        for(int i = 1; i < XandY.size(); i++)
        {
            if(XandY[i].second > Highest)
            {
                q = double(XandY[i].first - XandY[i - 1].first);
                p = double(XandY[i].second - XandY[i - 1].second);

                Distance +=  sqrt(pow(q, 2) + pow(p, 2)) * 
                    (XandY[i].second - Highest) 
                        / (XandY[i].second - XandY[i - 1].second);

                                                                        //Euclidian 
                                                                        //distance *
                                                                        //hight 
                                                                        //difference 
                                                                        //then devides
                                                                        // by the 
                                                                        //difference 
                                                                        //in distance 
                                                                        //of the two 
                                                                        //peaks

                Highest = XandY[i].second;
            }
        }

        cout << setprecision(2) << fixed << Distance << '\n';           //prints 2 
                                                                        //decimal places

        NumCases--;
    }

    return 0;
}