#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321;
int N, A[21][21], total = 0;

bool chk(int x, int y) {
	return x > 0 && x <= N&&y > 0 && y <= N;
}

int diff(int x, int y, int d1, int d2) {
	vector<int> people(5, 0);
	int B[21][21] = { 0, };
	int Min = INF;
	int Max = -INF;

	// 5 경계선 채우기
	for (int i = 0; i <= d1; i++) {
		B[x + i][y - i] = 5;
		B[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		B[x + i][y + i] = 5;
		B[x + d1 + i][y - d1 + i] = 5;
	}

	// 1 경계선 채우기
	for (int r = 1; r < x + d1; r++) {
		for (int c = 1; c <= y; c++) {
			if (B[r][c] == 5) break;
			people[0] += A[r][c];
		}
	}

	// 2 경계선 채우기
	for (int r = 1; r <= x + d2; r++) {
		for (int c = N; c > y; c--) {
			if (B[r][c] == 5) break;
			people[1] += A[r][c];
		}
	}

	// 3 경계선 채우기
	for (int r = x + d1; r <= N; r++) {
		for (int c = 1; c < y - d1 + d2; c++) {
			if (B[r][c] == 5) break;
			people[2] += A[r][c];
		}
	}

	// 4 경계선 채우기
	for (int r = x + d2 + 1; r <= N; r++) {
		for (int c = N; c >= y - d1 + d2; c--) {
			if (B[r][c] == 5) break;
			people[3] += A[r][c];
		}
	}
	people[4] = total - (people[0] + people[1] + people[2] + people[3]);
	sort(people.begin(), people.end());

	return people[4] - people[0];
}

int solve() {
	int res = INF;

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++) {
					if (!chk(x + d1 + d2, y - d1 + d2)) continue;
					res = min(res, diff(x, y, d1, d2));
				}
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			total += A[i][j];
		}
	}
	cout << solve() << '\n';
	return 0;
}