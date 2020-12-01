///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            10226
// Title:            10226
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it finds the average amount of trees in
//  a given set
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    int cases;
    string tree;

    cin >> cases;

    getline(cin, tree);
    getline(cin, tree);

    while(cases != 0)
    {
        map <string, int> treeCounter;  //map to key and value a tree
        int treeTotal = 0;
        
        while(getline(cin, tree))
        {
            if(tree == "")
            {
                break;
            }

            treeTotal++;

            treeCounter[tree]++;
        }

        for(map <string , int> :: iterator i = treeCounter.begin(); i != treeCounter.end(); i++)
        {
            cout << i->first << ' ' << fixed << setprecision(4) << i->second * (100.0/treeTotal) << '\n';
        }//prints the trees and there totals in order

        cases--;

        if(cases != 0)
        {
            cout << '\n';
        }
    }

    return 0;
}