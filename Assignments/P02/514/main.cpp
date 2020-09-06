///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            514
// Title:            UVA 514
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it takes in a set number of ordered 
//  trains and with that information it tries to rearrange them to fit in a 
//  given order. The catch is that there is a staging area where you can load 
//  the carts in order to try and rearrange them to solve the problem.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//                    Function:void solve(int t)
//
// Description:
//      This function takes in a number of cases then with that solves the 
//  train problem fallowing a given algorithm
//
/////////////////////////////////////////////////////////////////////////////////
void solve(int t)
{
	stack<int> start;
	stack<int> hold;
	queue<int> fin;

	int num;

	while (true)
	{
		for (int i = 0; i < t; i++)                 //loads goal unless given
                                                    //a 0
		{
			cin >> num;

			if (num == 0)
			{
				return;
			}

			fin.push(num);
		}

		for (int i = t; i >= 0; i--)
		{
			start.push(i);                          //loads start in order
		}

		while (true)
		{
			if (fin.empty())
			{
				cout << "Yes\n";                    //if it works
				break;
			}
			else if (!start.empty() && 
            start.top() == fin.front())             //if the end goals front 
                                                    //train and given train 
                                                    //match go straight across
			{
				start.pop();
				fin.pop();
			}
			else
			{
				if (!hold.empty() && hold.top() 
                == fin.front())                     //if staging matches 
                                                    //answer goes across
				{
					fin.pop();
					hold.pop();
				}
				else if (!start.empty())            //if start one needs 
                                                    //to go to the holding area
				{
					hold.push(start.top());
					start.pop();
				}
				else
				{
					cout << "No\n";
					while (!fin.empty())            //if cant happen clears all 
                                                    //stacks and queues and 
                                                    //breaks out
					{
						fin.pop();
					}
					while (!hold.empty())
					{
						hold.pop();
					}
					while (!fin.empty())
					{
						hold.pop();
					}

					break;
				}
			}
		}
	}
}

int main()
{
	int t;

	while (true)
	{
		cin >> t;

		if (t == 0)                             //ends prog if a zero is read
		{
			break;          
		}
		else
		{
			solve(t);                           //solves with algorithm

			cout << "\n";
		}
	}
}