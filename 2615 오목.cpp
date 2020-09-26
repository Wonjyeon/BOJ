#include <iostream>
using namespace std;

int map[20][20];
int N = 20;

int dx[] = { -1,0,1,1 };
int dy[] = { 1,1,1,0 };

int chk(int x, int y) {
	return x >= 1 && x < N && y >= 1 && y < N;
}

int solve(int sx, int sy, int color, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = sx;
		int ny = sy;
		int prev_x = sx - dx[i];
		int prev_y = sy - dy[i];

		if (map[prev_x][prev_y] == color)	// 6¸ñ ¹èÁ¦
			continue;

		for (int t = 0; t < 5; t++) {
			nx = nx + dx[i];
			ny = ny + dy[i];
			if (!chk(nx, ny) || map[nx][ny] != color)
				break;
			else {
				cnt++;
			}
		}
		if (cnt == 5) {
			return map[sx][sy];
		}
		cnt = 1;
	}
	return 0;
}

int main() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] == 1 || map[i][j] == 2) {
				int result = solve(i, j, map[i][j], 1);
				if (result) {
					printf("%d\n%d %d\n", result, i, j);
					return 0;
				}
			}
		}
	}
	cout << 0 << endl;
	return 0;
}