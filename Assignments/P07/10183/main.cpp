#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int a, b;

	vector<unsigned long long int> FibNums;

	FibNums.push_back(1);
	FibNums.push_back(2);

	for (int i = 2; i < 480; i++)
	{
		FibNums.push_back(FibNums[i - 1] + FibNums[i - 2]);
	}

	cin >> a >> b;

	while (a != 0 && b != 0)
	{
		int ans = 0;

		for (int i = 0; i < FibNums.size(); i++)
		{
			if (a <= FibNums[i])
			{
				a = i;
				break;
			}
		}

		while (FibNums[a] <= b)
		{
			ans++;
			a++;
		}

		cout << ans << '\n';

		cin >> a >> b;
	}

	return 0;
}