///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            127
// Title:            UVA 127
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it takes in a deck of cards and plays
//  a game of “Accordian” Patience where whenever the card can be moved left 3 
//  it prioritizes that over moving left 1.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    bool run = true;

    string card, temp;

    while (run)
    {
        vector<stack<string>> Deck(52);                         //deck of cards

        for (int i = 0; i < Deck.size(); i++)
        {
            cin >> card;
            if (card == "#")
            {
                i = 100;
                run = false;                                    //breaks on #
            }
            else
            {
                Deck[i].push(card);
            }
        }

        if (!run)
        {
            break;
        }

        for (int i = 1; i < Deck.size(); i++)
        {
            if (i >= 3 && 
            (Deck[i].top().at(0) == Deck[i - 3].top().at(0) 
            || Deck[i].top().at(1) == Deck[i - 3].top().at(1))) //moves card 3
            {

                Deck[i - 3].push(Deck[i].top());
                Deck[i].pop();

                if (Deck[i].empty())
                {
                    Deck.erase(Deck.begin() + i, Deck.begin()   //closes gaps
                    + (i + 1));
                }

                i -= 4;                                         //reduces index 
                                                                //efficiently
            }
            if (i >= 1 && 
            (Deck[i].top().at(0) == Deck[i - 1].top().at(0) 
            || Deck[i].top().at(1) == Deck[i - 1].top().at(1))) //moves cards 1
            {

                Deck[i - 1].push(Deck[i].top());
                Deck[i].pop();

                if (Deck[i].empty())
                {
                    Deck.erase(Deck.begin() + i, Deck.begin() + 
                    (i + 1));                                   //closes gaps
                }

                i -= 2;                                         //reduces index 
                                                                //efficiently
            }
        }

        if(Deck.size() == 1)
        {
            cout << Deck.size() << " pile remaining: ";
        }
        else
        {
            cout << Deck.size() << " piles remaining: ";
        }
        
        for (int i = 0; i < Deck.size(); i++)                   //output
        {
            cout << Deck[i].size();

            if(i != Deck.size() - 1)
            {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    return (0);
}