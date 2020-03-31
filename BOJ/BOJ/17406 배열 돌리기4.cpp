#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct OP {
	int r, c, s;
};
OP op[7];
int N, M, K, map[51][51], Temp[51][51], MIN = 987654321;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[7];
vector<int> v;

void cal() {
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += Temp[i][j];
		}
		MIN = min(MIN, sum);
	}
}

void change() {
	for (int i = 0; i < v.size(); i++) {
		int idx = v[i], x, y;
		int lx = op[idx].r - op[idx].s, ly = op[idx].c - op[idx].s;
		int rx = op[idx].r + op[idx].s, ry = op[idx].c + op[idx].s;

		int T = min(rx - lx + 1, ry - ly + 1) / 2;

		while (T--) {
			int x = lx, y = ly, dir = 0;
			int store = Temp[x][y];
			while (1) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx == lx&&ny == ly) {
					Temp[x][y] = store;
					break;
				}
				if (nx > rx || nx < lx || ny > ry || ny < ly) {
					dir++;
					continue;
				}
				Temp[x][y] = Temp[nx][ny];
				x = nx, y = ny;
			}
			lx += 1, ly += 1, rx -= 1, ry -= 1;
		}
	}
}

void solve(int cnt) {
	if (cnt == K) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				Temp[i][j] = map[i][j];
		change();
		cal();
		return;
	}
	for (int i = 1; i <= K; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		v.push_back(i);
		solve(cnt + 1);
		v.pop_back();
		visit[i] = false;
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		cin >> op[i].r >> op[i].c >> op[i].s;
	}
	solve(0);
	cout << MIN << '\n';
}