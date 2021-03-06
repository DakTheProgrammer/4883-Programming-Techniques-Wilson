///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            10194
// Title:            10194
// Course:           4883
// Semester:         Fall 2020
//
// Description:
//      This program is written in c++ and it finds the table for scoring a
//	soccer league/tournament
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////
//      				Struct: struct FootballTeam 
//
// Description:
//      A struct that holds and does algoritms for finding the table
//	values of a given team.
//
/////////////////////////////////////////////////////////////////////////
struct FootballTeam
{
	string name;
	int points;
	int gamesPlayed;
	int wins;
	int ties;
	int losses;
	int goalScore;
	int goalAgainst;
	int goalDiff;

	/////////////////////////////////////////////////////////////////////////
	//					method: FootballTeam(string x)
	//
	// Description:
	//      A constructor that makes a team with a name and a blank record
	//
	/////////////////////////////////////////////////////////////////////////
	FootballTeam(string x)
	{
		name = x;
		points = 0;
		gamesPlayed = 0;
		wins = 0;
		ties = 0;
		losses = 0;
		goalScore = 0;
		goalAgainst = 0;
		goalDiff = 0;
	}

	/////////////////////////////////////////////////////////////////////////
	//					method: FootballTeam()
	//
	// Description:
	//      A default constructor that makes defaulted everything
	//
	/////////////////////////////////////////////////////////////////////////
	FootballTeam()
	{
		name = "";
		points = 0;
		gamesPlayed = 0;
		wins = 0;
		ties = 0;
		losses = 0;
		goalScore = 0;
		goalAgainst = 0;
		goalDiff = 0;
	}

	/////////////////////////////////////////////////////////////////////////
	//					method: update(int GF, int GA)
	//
	// Description:
	//      A method that updates the teams values
	//
	/////////////////////////////////////////////////////////////////////////
	void update(int GF, int GA)
	{
		gamesPlayed++;

		if (GF > GA)//win
		{
			wins++;
			points += 3;
		}
		else if (GF < GA)//loss
		{
			losses++;
		}
		else//tie
		{
			ties++;
			points++;
		}

		goalScore += GF;
		goalAgainst += GA;
		goalDiff += (GF - GA);
	}
};

/////////////////////////////////////////////////////////////////////////
//			function: bool CMPR(FootballTeam a, FootballTeam b)
//
// Description:
//      A used to sort teams based on structure
//
/////////////////////////////////////////////////////////////////////////
bool CMPR(FootballTeam a, FootballTeam b)
{
	if(a.points != b.points)
	{
		return a.points > b.points;
	}
	else if(a.wins != b.wins)
	{
		return a.wins > b.wins;
	}
	else if(a.goalDiff != b.goalDiff)
	{
		return a.goalDiff > b.goalDiff;
	}
	else if(a.goalScore != b.goalScore)
	{
		return a.goalScore > b.goalScore;
	}
	else if(a.gamesPlayed != b.gamesPlayed)
	{
		return a.gamesPlayed < b.gamesPlayed;
	}
	else //sorts names by upcasing
	{
		for(int i = 0; i < a.name.length(); i++)
		{
			if(a.name.at(i) <= 90 && a.name.at(i) >= 65)
			{
				a.name.at(i) += 32;
			}
		}

		for(int i = 0; i < b.name.length(); i++)
		{
			if(b.name.at(i) <= 90 && b.name.at(i) >= 65)
			{
				b.name.at(i) += 32;
			}
		}


		if(a.name < b.name)
		{
			return a.name < b.name;
		}
		return false;
	}
}

int main()
{
	int NumTourn, Team1Score, Team2Score;
	string TeamName, temp, Team1, Team2, TournName;

	cin >> NumTourn;

	getline(cin, TournName);
	while (NumTourn != 0)
	{
        getline(cin, TournName);

		int NumTeam;

		cin >> NumTeam;

		vector<FootballTeam> Teams;

        getline(cin, TeamName);
		while (NumTeam != 0)
		{
            getline(cin, TeamName);

			Teams.push_back(FootballTeam(TeamName));

			NumTeam--;
		}

		int numGames;

		cin >> numGames;

		getline(cin, temp);
		while (numGames != 0)
		{
			int Cases = 0;
			string holder = "";

			
			getline(cin, temp);

			for (int i = 0; i < temp.length(); i++)
			{
                if(i == temp.length() - 1)
                {
                    holder += temp.at(i);
                }
                //check hash
				if(temp.at(i) == '#' || temp.at(i) == '@' || i == temp.length() - 1)
				{
					Cases++;

					switch (Cases)
					{
					case 1:
						Team1 = holder;
						holder = "";
						break;
					case 2:
						Team1Score = stoi(holder);
						holder = "";
						break;
					case 3:
                        Team2Score = stoi(holder);
						holder = "";
						break;
					case 4:
						Team2 = holder;
						holder = "";
						break;
					}
				}
                else
				{
					holder += temp.at(i);
				}
			}

			for (int i = 0; i < Teams.size(); i++)
			{
				if (Teams[i].name == Team1)
				{
					Teams[i].update(Team1Score, Team2Score);
				}
				else if (Teams[i].name == Team2)
				{
					Teams[i].update(Team2Score, Team1Score);
				}
			}

			numGames--;
		}

		sort(Teams.begin(), Teams.end(), CMPR);

		cout << TournName << '\n';

		for (int i = 0; i < Teams.size(); i++)//display
		{
			cout << i + 1 << ") " << Teams[i].name << ' ' << Teams[i].points << "p, " << Teams[i].gamesPlayed
				<< "g (" << Teams[i].wins << '-' << Teams[i].ties << '-'
				<< Teams[i].losses << "), " << Teams[i].goalDiff << "gd (" << Teams[i].goalScore << '-' << Teams[i].goalAgainst << ")\n";
		}

		

		NumTourn--;

		if(NumTourn != 0)
		{
			cout << '\n';
		}
	}
	return 0;
}