#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
int N, M;
int check[MAX][MAX] = { 0 };
int map[MAX][MAX] = { 0 };

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 & nx < N&&ny >= 0 && ny < M) {
				if (check[nx][ny] == 0 && map[nx][ny] == 1) {
					q.push({ nx,ny });
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	}

	bfs(0, 0);
	cout << check[N - 1][M - 1] << endl;
	return 0;
}