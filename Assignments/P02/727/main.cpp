///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            727
// Title:            UVA 727
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it takes in a math equation in infix 
//  form and converts it to postfix form using a stack to order how it is 
//  displayed
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>
#include <string>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//                    Function:bool Operand(char problem) 
//
// Description:
//      This function figures out if a char in a string is a operand 0-9
//
/////////////////////////////////////////////////////////////////////////////////
bool Operand(char problem) 
{
	if (problem == '0' || problem == '1' || problem == '2' || problem == '3' 
        || problem == '4' || problem == '5' || problem == '6' 
        || problem == '7' || problem == '8' || problem == '9') 
    {
		return true;
	}
	else 
    {
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
//                    Function:bool Operat(char problem) 
//
// Description:
//      This function figures out if a char in a string is a operator "+,-,/,*"
//
/////////////////////////////////////////////////////////////////////////////////
bool Operat(char problem)
{
	if (problem == '+' || problem == '-' || problem == '*' || problem == '/')
    {

		return true;
    }
	else
    {
		return false;
    }
}

///////////////////////////////////////////////////////////////////////////////
//                    Function:int ranking(char problem)
//
// Description:
//      This function figures out the priority of a givin char for display
//
/////////////////////////////////////////////////////////////////////////////////
int ranking(char problem) 
{
	switch (problem) {
        case ')':
            return 0;
            break;
        case '(': 
            return 0;
            break;
        case '+': 
            return 1;
            break;
        case '-': 
            return 1;
            break;
        case '/': 
            return 2;
            break;
        case '*': 
            return 2;
            break;
        default:
            return 100;                                 //used as backup
	}
}

int main() 
{
	int t;
    string blankLine, probChar, problem, output;

    stack<char> MyStack;

	cin >> t;

	getline(cin, blankLine);                            //used to read blank 
                                                        //lines
	getline(cin, blankLine);

	while(t != 0) 
    {
		
        while (getline(cin, probChar)) 
        {
			if (probChar.length() != 0) 
            {
				problem += probChar;                    //places problem into
                                                        //one string
			}
			else 
            {
				break;                                  //used to signal end 
                                                        //of set
			}
		}
		
		for (int i = 0; i < problem.length(); i++)      //loops through problem
        {
			if (Operand(problem.at(i)))                 //loads operands
            {
				output += problem.at(i);
			}
			else if (Operat(problem.at(i)))             //figures operations 
                                                        //placemnt
            {
				while (!MyStack.empty() && ranking(problem.at(i)) 
                    <= ranking(MyStack.top())) 
                {
					output += MyStack.top();            //outputs in order
					MyStack.pop();
				}

				MyStack.push(problem.at(i));
			}
			else if (problem.at(i) == '(') 
            {
				MyStack.push(problem.at(i));
			}
			else if (problem.at(i) == ')') 
            {
				while (MyStack.top() != '(') 
                {
					output += MyStack.top();            //tells brackets to
                                                        //come together
					MyStack.pop();
				}

				MyStack.pop();
			}
		}

		while (!MyStack.empty()) 
        {
			output += MyStack.top();                    //empties leftovers
			MyStack.pop();
		}
			
		cout << output << '\n';                         //prints answer

        output = "";
        problem = "";                                   //clears leftovers

        t--;

        if(t != 0)
        {
            cout << '\n';                               //used for output format
        }
	}

	return 0;
}