#include <iostream>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX];
int N;

void floyd()
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][k] && graph[k][j])
					graph[i][j] = 1;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	floyd();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}