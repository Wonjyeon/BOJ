#include <iostream>
using namespace std;
int Ctime[2000001] = { 0 };
int time[100] = { 0 };

int main()
{


	int N, C, Ctemp, temp;

	scanf("%d %d", &N, &C);

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &time[i]);
		Ctemp = C;
		temp = time[i];
		for (int j = 1; j <= C / time[i]; j++)
		{
			Ctime[temp - 1]++;
			temp += time[i];
		}
	}
	for (int i = 0; i < C; i++)
	{
		if (Ctime[i] != 0)
		{
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}