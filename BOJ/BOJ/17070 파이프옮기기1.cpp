#include <iostream>
using namespace std;

// ����, ����, �밢��
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };

int N, map[16][16];
int ans = 0;

// ����, �� check
int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < N&&y < N&&map[x][y] != 1;
}

void dfs(int tx, int ty, int dir) {
	int flag = 3;
	if (tx == N - 1 && ty == N - 1) {
		ans++;
		return;
	}
	if (dir == 0)
		flag = 1;
	else if (dir == 1)
		flag = 0;

	for (int i = 0; i < 3; i++) {
		// ���θ� ����X. ���θ� ����X.
		if (flag == i)
			continue;
		int nx = tx + dx[i];
		int ny = ty + dy[i];
		if (chk(nx, ny)) {
			// �밢�� ���� -> ������ ��ġ�� Ȯ��
			if (i == 2) {
				if (chk(nx, ny - 1) && chk(nx - 1, ny)) 
					dfs(nx, ny, i);
			}
			else {
				dfs(nx, ny, i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 1, 0);
	cout << ans << endl;
}