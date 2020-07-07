#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, M;
char map[50][50];
int visit[50][50];
int MaxPath = -1;
queue<int> cnt;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

void bfs(int s, int e) {

	visit[s][e] = 1;
	int pathLength;
	queue<pair<int, int>> q;
	q.push({ s,e });
	cnt.push(0);
	while (!q.empty()) {
		pathLength = cnt.front();
		cnt.pop();

		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] == 'L' && !visit[nx][ny] && chk(nx, ny)) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
				cnt.push(pathLength + 1);
			}
		}

	}
	if (pathLength > MaxPath)
		MaxPath = pathLength;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				bfs(i, j);
				init();
			}
		}
	}
	cout << MaxPath << endl;
	return 0;
}