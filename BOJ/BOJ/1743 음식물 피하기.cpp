#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool visit[MAX][MAX];
int map[MAX][MAX];

int N, M;
int cnt = 0;
int Max = -1;


void dfs(int x, int y)
{
	cnt++;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N&&ny >= 0 && ny < M)
		{
			if (map[nx][ny] == 1 && !visit[nx][ny])
			{
				dfs(nx, ny);
			}
		}
	}
}


int main()
{
	int K;
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cnt = 0;
			if (map[i][j] == 1 && !visit[i][j])
			{
				dfs(i, j);
				Max = max(Max, cnt);
			}
		}
	}
	cout << Max << endl;
}