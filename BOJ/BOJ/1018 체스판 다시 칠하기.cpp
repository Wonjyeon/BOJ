#include <iostream>
#include <algorithm>
using namespace std;

int N, M, Min = 987654321;
char map[51][51];

int solve(int x, int y) {
	int sum1 = 0, sum2 = 0;
	char even = map[x][y];
	char odd;
	if (even == 'B') odd = 'W';
	else odd = 'B';
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (j % 2 == 0) {
				if (map[i + x][j + y] != even)
					sum1++;
			}
			else {
				if (map[i + x][j + y] != odd)
					sum1++;
			}
		}
		swap(even, odd);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (j % 2 == 0) {
				if (map[i + x][j + y] != odd)
					sum2++;
			}
			else {
				if (map[i + x][j + y] != even)
					sum2++;
			}
		}
		swap(even, odd);
	}

	return min(sum1, sum2);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			Min = min(Min, solve(i, j));
		}
	}
	cout << Min << '\n';
}