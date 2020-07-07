#include <iostream>
using namespace std;

int main()
{
	int N;
	int small, large;
	int cnt = 1;
	int flag = 0;

	cin >> N >> small >> large;

	if (small > large)
	{
		int temp = small;
		small = large;
		large = temp;
	}

	while (1)
	{
		if (large - small == 1)
		{
			if (large % 2 == 0)
			{
				cout << cnt;
				return 0;
			}
		}

		small = (small + 1) / 2;
		large = (large + 1) / 2;
		cnt++;

	}
	return 0;
}