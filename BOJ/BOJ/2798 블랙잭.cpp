#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, ans;
	int card[100];

	scanf("%d %d", &N, &M);

	int m = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &card[i]);
	}
	for (int a = 0; a < N - 2; a++)
	{
		for (int b = a + 1; b < N - 1; b++)
		{
			for (int c = b + 1; c < N; c++)
			{
				ans = card[a] + card[b] + card[c];
				if (ans <= M)
					m = max(m, ans);
			}
		}
	}

	cout << m << endl;
}