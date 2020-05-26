#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, start_node, end_node, max_cost = 0;
vector<pair<int, int>> adj[100001];
bool check[100001];

void bfs(int mid) {
	queue<int> q;
	check[start_node] = true;
	q.push(start_node);
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < adj[node].size(); i++) {
			int next_node = adj[node][i].first;
			int next_cost = adj[node][i].second;
			if (check[next_node] || next_cost < mid)
				continue;
			check[next_node] = true;
			q.push(next_node);
		}
	}
}

bool isAvailable(int mid) {
	bfs(mid);
	return check[end_node];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int a, b, c, ans = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		max_cost = max(max_cost, c);
	}
	cin >> start_node >> end_node;
	int low = 1, high = max_cost, mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		memset(check, false, sizeof(check));
		if (isAvailable(mid)) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << '\n';
}