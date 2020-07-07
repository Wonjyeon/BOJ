#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, virus = 0, min_v = 100;
int map[8][8];
int visit[8][8];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

void dfs(int x, int y) {
	virus++;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] != 1 && !visit[nx][ny] && chk(nx, ny)) {
			dfs(nx, ny);
		}
	}
}

void comb(int depth) {
	if (depth == 3) {
		virus = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 2 && !visit[i][j]) {
					dfs(i, j);
				}
			}
		}
		min_v = min(min_v, virus);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				comb(depth + 1);
				map[i][j] = 0;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	int wall_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				wall_cnt++;
		}
	}
	comb(0);
	cout << (N*M) - wall_cnt - 3 - min_v << endl;
	return 0;
}