#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Max = 0, board[21][21];
vector<int> direction;

int findMax() {
	int Max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > Max) Max = board[i][j];
		}
	}
	return Max;
}
void saveMap(int a[21][21], int b[21][21]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void up() {
	// 열을 돌면서.
	for (int j = 0; j < N; j++) {
		int now = 0, now_idx = 0;
		// 행을 위에서부터 아래로. => 합쳐
		for (int i = 0; i < N; i++) {
			if (board[i][j] == 0) continue;
			if (now != board[i][j]) {
				now = board[i][j];
				now_idx = i;
			}
			else {
				now *= 2;
				board[now_idx][j] = now;
				board[i][j] = 0;
				now = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			if (board[i][j] != 0) {
				int num = board[i][j];
				board[i][j] = 0;
				int zero_idx = 0;
				for (zero_idx = i - 1; zero_idx >= 0; zero_idx--) {
					if (board[zero_idx][j] != 0) break;
				}
				board[zero_idx + 1][j] = num;
			}
		}
	}
}
void down() {
	// 열을 돌면서.
	for (int j = 0; j < N; j++) {
		int now = 0, now_idx = 0;
		// 행을 아래서부터 위로. => 합쳐
		for (int i = N - 1; i >= 0; i--) {
			if (board[i][j] == 0) continue;
			if (now != board[i][j]) {
				now = board[i][j];
				now_idx = i;
			}
			else {
				now *= 2;
				board[now_idx][j] = now;
				board[i][j] = 0;
				now = 0;
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			if (board[i][j] != 0) {
				int num = board[i][j];
				board[i][j] = 0;
				int zero_idx = 0;
				for (zero_idx = i + 1; zero_idx < N; zero_idx++) {
					if (board[zero_idx][j] != 0) break;
				}
				board[zero_idx - 1][j] = num;
			}
		}
	}
}
void left() {
	// 행을 돌면서.
	for (int i = 0; i < N; i++) {
		int now = 0, now_idx = 0;
		// 열을 왼쪽부터 오른쪽으로. => 합쳐
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			if (now != board[i][j]) {
				now = board[i][j];
				now_idx = j;
			}
			else {
				now *= 2;
				board[i][now_idx] = now;
				board[i][j] = 0;
				now = 0;
			}
		}
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) {
				int num = board[i][j];
				board[i][j] = 0;
				int zero_idx = 0;
				for (zero_idx = j - 1; zero_idx >= 0; zero_idx--) {
					if (board[i][zero_idx] != 0) break;
				}
				board[i][zero_idx + 1] = num;
			}
		}
	}
}
void right() {
	// 행을 돌면서.
	for (int i = 0; i < N; i++) {
		int now = 0, now_idx = 0;
		// 열을 오른쪽부터 왼쪽으로. => 합쳐
		for (int j = N - 1; j >= 0; j--) {
			if (board[i][j] == 0) continue;
			if (now != board[i][j]) {
				now = board[i][j];
				now_idx = j;
			}
			else {
				now *= 2;
				board[i][now_idx] = now;
				board[i][j] = 0;
				now = 0;
			}
		}
		for (int j = N - 1; j >= 0; j--) {
			if (board[i][j] != 0) {
				int num = board[i][j];
				board[i][j] = 0;
				int zero_idx = 0;
				for (zero_idx = j + 1; zero_idx < N; zero_idx++) {
					if (board[i][zero_idx] != 0) break;
				}
				board[i][zero_idx - 1] = num;
			}
		}
	}
}

void dfs(int dir, int cnt, int depth) {
	if (cnt == depth) {
		for (int i = 0; i < 5; i++) {
			int d = direction[i];
			switch (d)
			{
			case 1: up();
				break;
			case 2:	left();
				break;
			case 3: down();
				break;
			case 4: right();
				break;
			default:
				break;
			}
		}
		Max = max(Max, findMax());
		return;
	}
	for (int i = 1; i <= 4; i++) {
		int tmp[21][21];
		saveMap(tmp, board);
		direction.push_back(i);
		dfs(i, cnt + 1, depth);
		direction.pop_back();
		saveMap(board, tmp);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	dfs(0, 0, 5);
	cout << Max << '\n';
	return 0;
}