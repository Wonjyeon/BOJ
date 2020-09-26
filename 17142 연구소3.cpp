#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321
int N, M, map[50][50], visit[11], ans = INF, total = 0;
vector<pair<int, int>> virus;
vector<pair<int, int>> Select;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

int bfs() {
	int time = 0;
	int cnt = 0;
	queue<pair<int, int>> q;
	int B[50][50] = { 0, };
	for (int i = 0; i < Select.size(); i++) {
		q.push({ Select[i].first, Select[i].second });
		B[Select[i].first][Select[i].second] = 1;
	}
	while (!q.empty()) {
		int Size = q.size();
		time++;
		while (Size--) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!chk(nx, ny) || map[nx][ny] == 1 || B[nx][ny] == 1) continue;
				if (map[nx][ny] == 0)
					cnt++;
				if (cnt == total) {
					return time;
				}
				B[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
	return INF;
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		ans = min(ans, bfs());
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		Select.push_back({ virus[i].first, virus[i].second });
		dfs(i, cnt + 1);
		Select.pop_back();
		visit[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i, j });
			}
			if (map[i][j] == 0)
				total++;
		}
	}
	if (total == 0) {
		cout << 0 << '\n';
		return 0;
	}
	dfs(0, 0);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}