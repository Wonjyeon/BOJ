#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, T, map[500][500], ans = -1;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool visit[500][500];

void dfs(int x, int y, int sum, int cnt) {
	visit[x][y] = true;

	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (visit[nx][ny]) continue;
		dfs(nx, ny, sum + map[nx][ny], cnt + 1);
		visit[nx][ny] = false;
	}
}
void shape1(int x, int y) {
	int temp = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x][y + 2];
	ans = max(ans, temp);
}
void shape2(int x, int y) {
	int temp = map[x][y] + map[x + 1][y + 1] + map[x][y + 1] + map[x][y + 2];
	ans = max(ans, temp);
}
void shape3(int x, int y) {
	int temp = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
	ans = max(ans, temp);
}
void shape4(int x, int y) {
	int temp = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x + 1][y + 1];
	ans = max(ans, temp);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);


	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visit, false, sizeof(visit));
			dfs(i, j, map[i][j], 1);
			if (i >= 1 && j + 2 < M) shape1(i, j);
			if (i + 1 < N&&j + 2 < M) shape2(i, j);
			if (i + 2 < N&&j + 1 < M) shape3(i, j);
			if (i + 1 < N&&i >= 1 && j + 1 < M) shape4(i, j);
		}
	}
	cout << ans << '\n';
	return 0;
}