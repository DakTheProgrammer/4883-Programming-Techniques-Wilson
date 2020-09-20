///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            12347
// Title:            UVA 12347
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it takes in a pre ordered output for 
//  a given binary search tree then with recursion prints out the post order 
//  output.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//             void PreToPost(vector<int> PreOrder, int min, int max)
//
// Description:
//      This function uses recursion to search down a BST's given pre order and 
//  prints out the post order
//
/////////////////////////////////////////////////////////////////////////////////
void PreToPost(vector<int> PreOrder, int min, int max)
{
    static int i = 0;                                   //index marker

    if(PreOrder[i] < min || PreOrder[i] > max)          //breaks if not part of
                                                        //current subtree
    {
        return;
    }
    
    if(i == PreOrder.size())                            //breaks if the whole 
                                                        //vector has been 
                                                        //searched through
    {
        return;
    }

    int NodeHead = PreOrder[i++];                       //used for recursion as
                                                        //the value at the head

    PreToPost(PreOrder, min, NodeHead);                 //all values in the 
                                                        //left subtree

    PreToPost(PreOrder, NodeHead, max);                 //all values in the 
                                                        //right subtree

    cout << NodeHead << '\n';
}

int main()
{
    int x;

    vector<int> PreOrder;
    vector<int> InOrder;

    while(cin >> x)
    {
        PreOrder.emplace_back(x);
        InOrder.emplace_back(x);
    }

    sort(InOrder.begin(), InOrder.end());                   //sorts the inorder 
                                                            //vector to put 
                                                            //into inorder

    PreToPost(PreOrder, InOrder.front(), InOrder.back());
}