#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pos_map[11][11];
int ans_total = 0;
bool visit[11];

void dfs(int idx, int depth, int sum) {
	if (depth == 11) {
		ans_total = max(ans_total, sum);
		return;
	}
	for (int j = 0; j < 11; j++) {
		if (pos_map[idx][j] == 0 || visit[j]) continue;
		visit[j] = true;
		dfs(idx + 1, depth + 1, sum + pos_map[idx][j]);
		visit[j] = false;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans_total = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> pos_map[i][j];
			}
		}
		dfs(0, 0, 0);
		cout << ans_total << '\n';
	}
	return 0;
}
