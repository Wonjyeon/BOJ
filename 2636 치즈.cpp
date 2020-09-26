#include <iostream>
#include <vector>
using namespace std;



int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int map[100][100];
int visit[100][100];
int total = 0;
int time = 0;
int cnt = 0;
int N, M;

vector<int> timeV[100];

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] == 1) {
			map[nx][ny] = 0;
			visit[nx][ny] = 1;
			cnt++;
		}
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!map[nx][ny] && !visit[nx][ny] && chk(nx, ny)) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				total++;
		}
	}
	while (total != 0) {
		cnt = 0;
		dfs(0, 0);
		total -= cnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visit[i][j] = 0;
			}
		}
		time++;
	}
	cout << time << endl << cnt << endl;
	return 0;
}