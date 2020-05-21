#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
int N, M, D, ans = 0;
bool visit[16];
vector<pair<int, int>> army;
vector<pair<int, int>> o_enemy;

int playGame() {
	vector<pair<int, int>> enemy = o_enemy;
	int total = enemy.size();
	int Count = 0;
	int visit[300] = { 0, };
	while (total) {
		for (int i = 0; i < 3; i++) {
			int ax = army[i].first, ay = army[i].second;
			int minD = INF, minY = INF, minIdx = INF;
			for (int j = 0; j < enemy.size(); j++) {
				if (visit[j] == 2)
					continue;
				int ex = enemy[j].first, ey = enemy[j].second;
				int dist = abs(ax - ex) + abs(ay - ey);
				if (dist > D) continue;
				if (dist < minD || (dist == minD && ey < minY))
					minD = dist, minY = ey, minIdx = j;
			}
			if (minIdx != INF && visit[minIdx] == 0) {
				total--;
				Count++;
				visit[minIdx] = 1;
			}
		}
		for (int i = 0; i < enemy.size(); i++) {
			if (visit[i] == 2)
				continue;
			if (visit[i] == 1) {
				visit[i] = 2;
				continue;
			}
			enemy[i].first++;
			if (enemy[i].first == N) {
				visit[i] = 2;
				total--;
			}
		}
	}
	return Count;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		ans = max(ans, playGame());
		return;
	}
	for (int i = idx; i < M; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		army.push_back({ N, i });
		dfs(i + 1, cnt + 1);
		army.pop_back();
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> D;
	int n;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> n;
			if (n == 1) o_enemy.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << ans << '\n';
}