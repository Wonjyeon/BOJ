#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visited[25][25] = { 0 };
int map[25][25] = { 0 };
int group_id = 0;
int groups[25 * 25] = { 0 };


void dfs(int x, int y)
{
	visited[x][y] = 1;
	groups[group_id]++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N&&ny >= 0 && ny < N)
		{
			if (map[nx][ny] == 1 && visited[nx][ny] == 0)
				dfs(nx, ny);
		}

	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				group_id++;
				dfs(i, j);
			}
		}
	}
	sort(groups + 1, groups + group_id + 1);
	printf("%d\n", group_id);
	for (int i = 1; i <= group_id; i++)
	{
		cout << groups[i] << endl;
	}

	return 0;
}