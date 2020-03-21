#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ans = -1;
vector<int> map[101];
int visit[101];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ans++;

		for (int i = 0; i < map[now].size(); i++) {
			if (!visit[map[now][i]]) {
				visit[map[now][i]] = 1;
				q.push(map[now][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	bfs(1);

	cout << ans << endl;
}