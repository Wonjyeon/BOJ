#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, H, ans = 10;
bool visit[11][31];

bool solve() {
	for (int n = 1; n <= N; n++) {
		int now_num = n;
		for (int i = 1; i <= H; i++) {
			if (visit[now_num][i])
				now_num = now_num + 1;
			else if (visit[now_num - 1][i])
				now_num = now_num - 1;
		}
		if (now_num != n) return false;
	}
	return true;
}

void dfs(int idx, int cnt) {
	if (cnt > 3 || ans < cnt)
		return;
	if (solve()) {
		ans = min(ans, cnt);
	}
	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (visit[j][i]) continue;
			if (visit[j - 1][i]) continue;
			if (visit[j + 1][i]) continue;

			visit[j][i] = true;
			dfs(i, cnt + 1);
			visit[j][i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		visit[b][a] = 1;
	}
	dfs(1, 0);
	if (ans == 10) ans = -1;
	cout << ans << '\n';
	return 0;
}