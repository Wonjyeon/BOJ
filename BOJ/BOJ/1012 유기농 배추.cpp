#include <iostream>
using namespace std;

#define MAX 51

int map[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (map[nx][ny] == 1 && !visit[nx][ny])
				dfs(nx, ny);
		}
	}
}

int main()
{
	int T, K;
	cin >> T;
	while (T--)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map[i][j] = 0;
				visit[i][j] = false;
			}
		}
		cin >> M >> N >> K;
		while (K--)
		{
			int c, r;
			cin >> c >> r;
			map[r][c] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1 && !visit[i][j])
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
}