#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int N;
	double K;
	double sum = 0;
	double var = 0;
	double ans = -1;
	double avg = 0;

	cin >> N >> K;

	vector<int> doll = vector<int>(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> doll[i];
	}

	while (K <= N)
	{
		for (int i = 0; i <= N - K; i++)
		{
			sum = 0;
			var = 0;
			for (int j = 0; j < K; j++)
			{
				sum += doll[i + j];
			}
			avg = sum / K;
			for (int j = 0; j < K; j++)
			{
				var += (doll[i + j] - avg)*(doll[i + j] - avg);
			}
			if (ans == -1)
				ans = var / K;
			else if (ans > var / K)
				ans = var / K;
		}
		K++;
	}

	printf("%.11lf\n", sqrt(ans));
}