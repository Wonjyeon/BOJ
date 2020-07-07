#include <iostream>
#include <algorithm>
using namespace std;

int N, L, map[100][100];

int solution() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int prev = map[i][0];
		int cnt = 0;
		int flag = 2;
		for (int j = 0; j < N; j++) {
			if (map[i][j] == prev) {
				cnt++;
				if (cnt == N) {
					ans++;
					break;
				}
			}
			else if (abs(map[i][j] - prev) > 1) break;
			else {
				if (prev < map[i][j]) {
					if ((flag == -1 && cnt < 2 * L) || cnt < L) break;
					prev = map[i][j];
					cnt = 0;
					j--;
					flag = 1;
				}
				else if (prev > map[i][j]) {
					prev = map[i][j];
					flag = -1;
					cnt = 0;
					int k;
					int cnt2 = 1;
					for (k = j + 1; k < N; k++) {
						if (map[i][k] != prev) break;
						cnt2++;
					}
					if (cnt2 < L) break;
					if (k == N) {
						ans++;
						break;
					}
					else j--;
				}
			}
			if (j == N - 1) ans++;
		}
	}
	for (int i = 0; i < N; i++) {
		int prev = map[0][i];
		int cnt = 0;
		int flag = 2;
		for (int j = 0; j < N; j++) {
			if (map[j][i] == prev) {
				cnt++;
				if (cnt == N) {
					ans++;
					break;
				}
			}
			else if (abs(map[j][i] - prev) > 1) break;
			else {
				if (prev < map[j][i]) {
					if ((flag == -1 && cnt < 2 * L) || cnt < L) break;
					prev = map[j][i];
					cnt = 0;
					j--;
					flag = 1;
				}
				else if (prev > map[j][i]) {
					prev = map[j][i];
					flag = -1;
					cnt = 0;
					int k;
					int cnt2 = 1;
					for (k = j + 1; k < N; k++) {
						if (map[k][i] != prev) break;
						cnt2++;
					}
					if (cnt2 < L) break;
					if (k == N) {
						ans++;
						break;
					}
					else j--;
				}
			}
			if (j == N - 1) ans++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << solution() << '\n';
	return 0;
}