#include <iostream>
using namespace std;

int main()
{
	int people[50][2];
	int cnt[50] = { 0 };
	int num;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> people[i][0] >> people[i][1];
	}
	for (int i = 0; i < N; i++)
	{
		num = 1;
		for (int j = 0; j < N; j++)
		{
			if (people[i][0] - people[j][0] < 0 && people[i][1] - people[j][1] < 0)
				num++;
		}
		cnt[i] = num;
		cout << cnt[i] << " ";
	}

}