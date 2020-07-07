#include <iostream>
#include <algorithm>
using namespace std;

int N, M, r, c, d, ans = 0;
int map[50][50];
int check[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

bool chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	ans = 1;
	check[r][c] = 1;
	while (1) {
		int cnt = 0;
		// 네 방향 체크
		for (int i = 0; i < 4; i++) {
			int x = r + dx[i], y = c + dy[i];
			if (map[x][y] == 1 || check[x][y] == 1 || !chk(x, y))
				cnt++;
		}
		// 뒤가 벽인지 체크
		if (cnt == 4) {
			r = r - dx[d], c = c - dy[d];
			if (map[r][c] == 1)
				break;
			continue;
		}

		int left_dir = (d + 3) % 4;
		int nr = r + dx[left_dir], nc = c + dy[left_dir];
		// 옆을 청소할 수 있다면
		if (map[nr][nc] != 1 && !check[nr][nc] && chk(nr, nc)) {
			check[nr][nc] = 1;
			r = nr, c = nc;
			d = (d + 3) % 4;
			ans++;
			continue;
		}
		else {
			d = (d + 3) % 4;
		}
	}
	cout << ans << '\n';
	return 0;
}