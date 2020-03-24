#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const long long INF = 1e12;
int N, M, start, dest;
long long dist[1001];
vector<pair<int, int>> v[1001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	fill(dist, dist + N + 1, INF);
	for (int i = 0; i < M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ y,c });
	}
	cin >> start >> dest;
	priority_queue<pair<long long, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (dist[next] > cost + nextcost) {
				dist[next] = cost + nextcost;
				pq.push({ -dist[next], next });
			}
		}
	}
	cout << dist[dest] << '\n';
}