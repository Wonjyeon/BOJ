#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100;
char map[MAX][MAX];
char map2[MAX][MAX];
int visit[MAX][MAX];
int N;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y, char c)
{
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N&&ny >= 0 && ny < N)
		{
			if (!visit[nx][ny] && map[nx][ny] == c)
				dfs(nx, ny, c);
		}
	}
}

int main()
{
	int cnt1 = 0;
	int cnt2 = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	//¡§ªÛ¿Œ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				cnt1++;
				dfs(i, j, map[i][j]);
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				cnt2++;
				dfs(i, j, map[i][j]);
			}
		}
	}
	cout << cnt1 << " " << cnt2 << endl;

	return 0;
}