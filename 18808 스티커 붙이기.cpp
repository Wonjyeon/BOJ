#include <iostream>
#include <cstring>
using namespace std;

struct Sticky {
	int r, c;
	int map[10][10];
};

Sticky s[100];
int N, M, K, R, C, ans = 0;
int note[40][40];

void change_note(int x, int y, int r, int c, int k) {
	for (int i = x; i < x + r; i++) {
		for (int j = y; j < y + c; j++) {
			if (s[k].map[i - x][j - y] == 0)
				continue;
			note[i][j] = 1;
		}
	}
}

void rotate(int k) {
	int tmp[10][10] = { 0, };
	int r = s[k].r, c = s[k].c;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			tmp[i][j] = s[k].map[r - j - 1][i];
		}
	}
	s[k].c = r, s[k].r = c;
	memset(s[k].map, 0, sizeof(s[k].map));
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			s[k].map[i][j] = tmp[i][j];
		}
	}
}

void solve(int k) {
	int rotate_cnt = 0;
	while (1) {
		int r = s[k].r, c = s[k].c;
		if (rotate_cnt == 5)
			return;
		if (N < r || M < c) {
			rotate(k);
			rotate_cnt++;
			continue;
		}
		int ans_x = 0, ans_y = 0;
		int Ri = 0, Ci = 0;
		for (int i = 0; i <= N - r; i++) {
			Ri = 0, Ci = 0;
			for (int j = 0; j <= M - c; j++) {
				// 붙일 수 없어 -> 옆칸으로 이동, 리셋
				if (note[i + Ri][j + Ci] == 1 && s[k].map[Ri][Ci] == 1) {
					Ri = 0, Ci = 0;
					continue;
				}
				// 지금 열은 붙일 수 있어.
				Ci++;
				// 지금 행의 열이 다 동일했어. -> 다음 행 비교하려고 Ri++. j는 다시 처음으로.
				if (Ci == c) {
					Ci = 0;
					Ri++;
					ans_y = j;
				}
				// 행까지 모두 동일했다는 거!
				if (Ri == r) {
					ans_x = i;
					change_note(ans_x, ans_y, r, c, k);
					return;
				}
				j = j - 1;
			}
		}
		if (Ri != r) {
			rotate(k);
			rotate_cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		cin >> R >> C;
		s[k].r = R, s[k].c = C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> s[k].map[i][j];
			}
		}
	}
	for (int i = 0; i < K; i++)
		solve(i);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (note[i][j]) ans++;
	cout << ans << '\n';
	return 0;
}