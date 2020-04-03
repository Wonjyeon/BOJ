#include <iostream>
#include <queue>
using namespace std;

struct Rotate {
	int x, d, k;
};
Rotate ro[50];
int N, M, T, total = 0, cnt = 0, map[51][51];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

// 회전
void rotate(int x, int d, int k) {
	int col = x;
	int arr[50];
	while (col <= N) {
		for (int row = 0; row < M; row++) {
			int nrow = row + dy[d] * k;
			// 시계방향으로 돌다가
			if (nrow >= M) nrow -= M;
			// 반시계 방향으로 돌다가
			if (nrow < 0) nrow += M;
			arr[nrow] = map[col][row];
		}
		for (int row = 0; row < M; row++) {
			map[col][row] = arr[row];
		}
		col += x;
	}
}
// 원판 수정
void change() {
	int flag = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			int visit[51][51] = { 0, };
			queue<pair<int, int>> q;
			int num = map[i][j];
			int Count = 0;
			q.push({ i, j });
			visit[i][j] = 1;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx == 0 || nx == N + 1) continue;
					if (ny < 0) ny = M - 1;
					if (ny == M) ny = 0;
					if (num == map[nx][ny] && !visit[nx][ny]) {
						q.push({ nx, ny });
						visit[nx][ny] = 1;
						map[nx][ny] = 0;
						Count++;
					}
				}
			}
			if (Count > 0) {
				flag = 1;
				total -= (Count + 1)*map[i][j];
				cnt -= Count + 1;
				map[i][j] = 0;
			}
		}
	}
	if (flag == 1) {
		return;
	}
	double mid = double(total) / double(cnt);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			if (map[i][j] > mid) map[i][j]--, total--;
			else if (map[i][j] < mid) map[i][j]++, total++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			total += map[i][j];
			cnt++;
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> ro[i].x >> ro[i].d >> ro[i].k;
		if (ro[i].k > M / 2) {
			ro[i].k = M - ro[i].k;
			if (ro[i].d == 0) ro[i].d = 1;
			else ro[i].d = 0;
		}
	}
	for (int t = 0; t < T; t++) {
		rotate(ro[t].x, ro[t].d, ro[t].k);
		if (total == 0) break;
		change();
	}
	cout << total << '\n';
}