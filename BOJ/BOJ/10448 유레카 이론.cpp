#include <iostream>
using namespace std;

int sol(int i)
{
	int ans = i*(i + 1) / 2;
	return ans;
}

int main()
{
	int T, K;
	cin >> T;
	while (T--)
	{
		int flag = 0;
		cin >> K;
		for (int i = 1; i < K; i++)
		{
			for (int j = 1; j < K; j++)
			{
				for (int p = 1; p < K; p++)
				{
					if (sol(i) + sol(j) + sol(p) == K)
					{
						cout << 1 << endl;
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
			}
			if (flag == 1)
				break;
		}
		if (flag == 0)
			cout << 0 << endl;
	}
	return 0;
}