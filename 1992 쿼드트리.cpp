#include <iostream>
using namespace std;

int N, map[64][64];

void solve(int x, int y, int Size) {
	int temp = map[x][y];
	for (int i = x; i < x + Size; i++) {
		for (int j = y; j < y + Size; j++) {
			if (map[i][j] != temp) {
				cout << '(';
				solve(x, y, Size / 2);
				solve(x, y + Size / 2, Size / 2);
				solve(x + Size / 2, y, Size / 2);
				solve(x + Size / 2, y + Size / 2, Size / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << temp;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	solve(0, 0, N);
	return 0;
}