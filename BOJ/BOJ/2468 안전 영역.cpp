#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 101;
int map[MAX][MAX] = { 0 };
int visit[MAX][MAX] = { 0 };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int Max = 1;
int N;

void dfs(int x, int y, int h)
{
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N&&ny >= 0 && ny < N)
		{
			if (visit[nx][ny] == 0 && map[nx][ny] > h)
				dfs(nx, ny, h);
		}
	}
}

int main()
{
	int max_h = 1;
	int min_h = 100;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> map[i][j];
			max_h = max(max_h, map[i][j]);
			min_h = min(min_h, map[i][j]);
		}
	}
	for (int i = min_h; i < max_h; i++)
	{
		memset(visit, 0, sizeof(visit));
		int cnt = 0;
		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < N; b++)
			{
				if (visit[a][b] == 0 && map[a][b] > i)
				{
					dfs(a, b, i);
					cnt++;
				}
			}
		}
		Max = max(Max, cnt);
	}
	cout << Max << endl;
}