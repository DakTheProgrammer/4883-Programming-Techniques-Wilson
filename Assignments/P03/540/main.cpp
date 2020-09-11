///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            540
// Title:            UVA 540
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it takes in series of groups and 
//  there numbers and with that it uses a team system of queues that prints 
//  them in order of which team is in the front. 
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int groups, groupsize, num, tester;
    int scenarios = 1;

    string EnDeStop;

    cin >> groups;

    while(groups != 0)
    {
        queue<int> teamplace;                           //used for which team is 
                                                        //in front

        vector<int> team(1000000);                      //used to mark the teams 
                                                        //position based on the 
                                                        //number input

        vector<queue<int>> teamqueue(1000);             //the team queue used for 
                                                        //output

        for(int i = 0; i < groups; i++)
        {
            cin >> groupsize;

            for(int j = 0; j < groupsize; j++)
            {
                cin >> num;
                team[num] = i;                          //puts group number at 
                                                        //element
            }
        }

        cout << "Scenario #" << scenarios << '\n'; 

        cin >> EnDeStop;                                //ENQUEUE DEQUEUE STOP

        while(EnDeStop != "STOP")
        {
            if(EnDeStop == "ENQUEUE")
            {
                cin >> tester;

                if(teamqueue[team[tester]].empty())
                {
                    teamplace.push(team[tester]);       //pushes onto queue if 
                                                        //team isn't on it yet
                }

                teamqueue[team[tester]].push(tester);   //puts number in place 
                                                        //in teamqueue
            }
            else
            {
                cout << 
                teamqueue[teamplace.front()].front() 
                << '\n';

                teamqueue[teamplace.front()].pop();     //removes output element

                if(teamqueue[teamplace.front()].empty())
                {
                    teamplace.pop();                    //pops if team is no 
                                                        //longer in the front
                }
            }

            cin >> EnDeStop;            
        }

        cout << '\n';

        scenarios++;

        cin >> groups;
    }

    return 0;
}