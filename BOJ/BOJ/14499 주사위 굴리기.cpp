#include <iostream>
using namespace std;

int N, M, x, y, K, dir, map[20][20], arr[7];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

bool chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	while (K--) {
		cin >> dir;
		if (!chk(x + dx[dir], y + dy[dir])) continue;
		x += dx[dir], y += dy[dir];
		if (dir == 1) {
			int tmp = arr[1];
			arr[1] = arr[4];
			arr[4] = arr[6];
			arr[6] = arr[3];
			arr[3] = tmp;
		}
		else if (dir == 2) {
			int tmp = arr[1];
			arr[1] = arr[3];
			arr[3] = arr[6];
			arr[6] = arr[4];
			arr[4] = tmp;
		}
		else if (dir == 3) {
			int tmp = arr[1];
			arr[1] = arr[5];
			arr[5] = arr[6];
			arr[6] = arr[2];
			arr[2] = tmp;
		}
		else if (dir == 4) {
			int tmp = arr[1];
			arr[1] = arr[2];
			arr[2] = arr[6];
			arr[6] = arr[5];
			arr[5] = tmp;
		}

		if (map[x][y] == 0) map[x][y] = arr[6];
		else {
			arr[6] = map[x][y];
			map[x][y] = 0;
		}
		cout << arr[1] << '\n';
	}
	return 0;
}