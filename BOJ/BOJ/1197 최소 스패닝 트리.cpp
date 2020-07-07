#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E, visit[100001], result = 0;
vector<pair<int, int>> edge[100001];
priority_queue<pair<int, int>> pq;

void prim() {
	visit[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		auto u = pq.top();
		pq.pop();
		if (!visit[u.second]) {
			visit[u.second] = true;
			result += -u.first;
			for (int i = 0; i < edge[u.second].size(); i++) {
				if (!visit[edge[u.second][i].second])
					pq.push({ -edge[u.second][i].first, edge[u.second][i].second });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[x].push_back({ z,y });
		edge[y].push_back({ z,x });
	}
	prim();
	cout << result << endl;
	return 0;
}