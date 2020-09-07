#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 52;

int main()
{
    bool run = true;

    string card, temp;

    while(run)
    {
        vector<stack<string>> Deck(52);

        for(int i = 0; i < SIZE; i++)
        {
            cin >> card;
            if(card == "#")
            {
                i = 100;
                run = false;
            }
            else
            {
                Deck[i].push(card);
            }
        }

        for(int i = 0; i < SIZE; i++)
        {
            if(!Deck[i+1].empty() && (Deck[i].top().at(0) == Deck[i+1].top().at(0) || Deck[i].top().at(1) == Deck[i+1].top().at(1)))
            {
                Deck[i].push(Deck[i+1].top());
                Deck[i+1].pop();

                if(Deck[i+1].empty())
                {
                    //close gap
                }

                i = -1;
            }
            else if(!Deck[i+3].empty() && (Deck[i].top().at(0) == Deck[i+3].top().at(0) || Deck[i].top().at(1) == Deck[i+3].top().at(1)))
            {
                Deck[i].push(Deck[i+3].top());
                Deck[i+3].pop();

                if(Deck[i+3].empty())
                {
                    //close gap
                }

                i = -1;
            }
        }

        cout << Deck.size() << "piles remaining: ";

        for(int i = 0; i < Deck.size(); i++)
        {
            cout << Deck[i].size() << ' ';
        }
        
        cout << '\n';

    }

    return(0);
}