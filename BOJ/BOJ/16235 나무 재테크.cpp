#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, A[11][11], B[11][11];
int dx[] = { 1,-1,0,0,-1,1,-1,1 };
int dy[] = { 0,0,1,-1,1,-1,-1,1 };
vector<int> map[11][11];

void solve() {
	//봄, 여름
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].size() == 0) continue;

			vector<int> age;
			int dead_sum = 0;
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end());
			}
			for (int k = 0; k < map[i][j].size(); k++) {
				if (map[i][j][k] > B[i][j]) {
					dead_sum += map[i][j][k] / 2;
					continue;
				}
				B[i][j] -= map[i][j][k];
				age.push_back(map[i][j][k] + 1);
			}
			map[i][j].clear();
			map[i][j] = age;
			B[i][j] += dead_sum;
		}
	}

	//가을
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				if (map[i][j][k] % 5 == 0) {
					int age = map[i][j][k];
					for (int d = 0; d < 8; d++) {
						int nx = i + dx[d], ny = j + dy[d];
						if (nx >= 1 && nx <= N&&ny >= 1 && ny <= N) {
							map[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}

	//겨울
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			B[i][j] += A[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			B[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x][y].push_back(z);
	}
	while (K--) {
		solve();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += map[i][j].size();
		}
	}
	cout << ans << '\n';
}