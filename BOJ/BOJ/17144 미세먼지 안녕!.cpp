#include <iostream>
#include <cstring>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int R, C, T, map[50][50];
int top_x = 0, bottom_x = 0;

bool chk(int x, int y) {
	return x >= 0 && y >= 0 && x < R&&y < C;
}

// 공기 확산
void spread() {
	int plus[50][50] = { 0, };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] < 5) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (chk(nx, ny) && map[nx][ny] != -1) {
					plus[nx][ny] += map[i][j] / 5;
					cnt++;
				}
			}
			map[i][j] -= cnt*(map[i][j] / 5);
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += plus[i][j];
		}
	}
}

// 공기 청정
void clean() {
	int x = top_x - 1, y = 0, i = 0;
	while (1) {
		if (x == top_x&&y == 1) {
			map[x][y] = 0;
			break;
		}
		int nx = x + dx[i], ny = y + dy[i];
		if (!chk(nx, ny) || nx > top_x) {
			i++;
			continue;
		}
		map[x][y] = map[nx][ny];
		x = nx, y = ny;
	}
	x = bottom_x + 1, y = 0, i = 0;
	while (1) {
		if (x == bottom_x && y == 1) {
			map[x][y] = 0;
			break;
		}
		int nx = x + dx[(i + 2) % 4], ny = y + dy[i];
		if (!chk(nx, ny) || nx < bottom_x) {
			i++;
			continue;
		}
		map[x][y] = map[nx][ny];
		x = nx, y = ny;
	}
}

int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (top_x == 0) top_x = i;
				else bottom_x = i;
			}
		}
	}
	while (T--) {
		spread();
		clean();
	}
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0)
				ans += map[i][j];
		}
	}
	cout << ans << '\n';
	return 0;
}