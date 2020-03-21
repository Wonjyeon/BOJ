#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 50;

int w, h;
int map[MAX][MAX];
bool visit[MAX][MAX];
int cnt = 0;

int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };

void dfs(int x, int y)
{
	visit[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < h&&ny >= 0 && ny < w)
		{
			if (map[nx][ny] == 1 && !visit[nx][ny])
				dfs(nx, ny);
		}
	}
}

int main()
{
	while (1)
	{
		cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && !visit[i][j])
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				visit[i][j] = false;
				map[i][j] = 0;
			}
		}

	}
}