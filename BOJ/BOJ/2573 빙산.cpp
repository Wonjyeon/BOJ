#include <iostream>
using namespace std;

int map[300][300];
int dx[] = { -1,1, 0, 0 };
int dy[] = { 0,0,-1,1 };
int visit[300][300];
int N, M;

int ice_cnt = 0;


int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

void dfs(int x, int y) {
	int zero = 0;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk(nx, ny) && !map[nx][ny] && !visit[nx][ny]) {
			zero++;
		}
	}
	map[x][y] -= zero;
	if (map[x][y] < 0)
		map[x][y] = 0;
	if (map[x][y] == 0) {
		ice_cnt++;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk(nx, ny) && !visit[nx][ny] && map[nx][ny] != 0)
			dfs(nx, ny);
	}
}

int main() {
	int total = 0;
	int time = 0;
	int group_cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0)
				total++;
		}
	}
	while (total > 0) {
		time++;
		group_cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0 && !visit[i][j]) {
					ice_cnt = 0;
					dfs(i, j);
					group_cnt++;
					if (group_cnt > 1) {
						break;
					}

				}

			}
		}
		if (group_cnt > 1) {
			break;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visit[i][j] = 0;
			}
		}
		total -= ice_cnt;
	}
	if (group_cnt > 1 && total != 0)
		cout << time - 1 << endl;
	else
		cout << 0 << endl;
}