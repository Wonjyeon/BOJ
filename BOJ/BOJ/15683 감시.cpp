#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, map[8][8], check[8][8], ans = 987654321, Count = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<pair<int, int>, int>> cctv;

void mark(int x, int y, int d, int n) {
	int nx = x, ny = y;
	while (1) {
		nx = nx + dx[d];
		ny = ny + dy[d];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
		if (map[nx][ny] == 6) break;
		check[nx][ny] += n;
	}
}

void dfs(int idx) {
	if (idx == Count) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0 && check[i][j] == 0)
					sum++;
			}
		}
		ans = min(ans, sum);
		return;
	}
	int type = cctv[idx].second;
	int x = cctv[idx].first.first;
	int y = cctv[idx].first.second;
	if (type == 1) {
		for (int i = 0; i < 4; i++) {
			mark(x, y, i, 1);
			dfs(idx + 1);
			mark(x, y, i, -1);
		}
	}
	else if (type == 2) {
		for (int i = 0; i < 2; i++) {
			mark(x, y, i, 1);
			mark(x, y, i + 2, 1);
			dfs(idx + 1);
			mark(x, y, i, -1);
			mark(x, y, i + 2, -1);
		}
	}
	else if (type == 3) {
		for (int i = 0; i < 4; i++) {
			mark(x, y, i, 1);
			mark(x, y, (i + 1) % 4, 1);
			dfs(idx + 1);
			mark(x, y, i, -1);
			mark(x, y, (i + 1) % 4, -1);
		}
	}
	else if (type == 4) {
		for (int i = 0; i < 4; i++) {
			mark(x, y, i, 1);
			mark(x, y, (i + 1) % 4, 1);
			mark(x, y, (i + 2) % 4, 1);
			dfs(idx + 1);
			mark(x, y, i, -1);
			mark(x, y, (i + 1) % 4, -1);
			mark(x, y, (i + 2) % 4, -1);
		}
	}
	else if (type == 5) {
		for (int i = 0; i < 4; i++) {
			mark(x, y, i, 1);
		}
		dfs(idx + 1);
		for (int i = 0; i < 4; i++) {
			mark(x, y, i, -1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv.push_back({ { i,j },map[i][j] });
				Count++;
			}
		}
	}
	dfs(0);
	cout << ans << '\n';
}