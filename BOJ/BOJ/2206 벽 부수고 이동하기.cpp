#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, ans = INF;
int map[1000][1000];
int d[1000][1000];
int d2[1000][1000];
int visit[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

void bfs() {
	queue<pair<int, int>> q;
	d2[0][0] = 1;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!chk(nx, ny) || d2[nx][ny] || d2[nx][ny] > ans) continue;
			if (map[nx][ny] == 0) {
				q.push({ nx,ny });
				d2[nx][ny] = d2[x][y] + 1;
				continue;
			}
			int Min = INF;
			for (int j = 0; j < 4; j++) {
				int nnx = nx + dx[j], nny = ny + dy[j];
				if (!chk(nnx, nny) || d[nnx][nny] < 1) continue;
				Min = min(Min, d[nnx][nny]);
			}
			ans = min(ans, d2[x][y] + Min + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	queue<pair<int, int>> q;
	q.push({ N - 1, M - 1 });
	d[N - 1][M - 1] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!chk(nx, ny) || d[nx][ny] || map[nx][ny] == 1) continue;
			d[nx][ny] = d[x][y] + 1;
			q.push({ nx, ny });
		}
	}
	if (d[0][0] != 0) {
		ans = d[0][0];
	}
	bfs();
	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}
