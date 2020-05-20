#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20001;
const int INF = 987654321;

int V, E, K;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex) {
	vector<int> dist(vertex, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		// 이미 작은 값을 가지고 있으니까 pass
		if (dist[curVertex] < cost)
			continue;

		for (int i = 0; i < graph[curVertex].size(); i++) {
			int neighbor = graph[curVertex][i].first;
			int nDistance = cost + graph[curVertex][i].second;

			if (dist[neighbor] > nDistance)
			{
				dist[neighbor] = nDistance;
				pq.push(make_pair(-nDistance, neighbor));
			}
		}
	}
	return dist;
}

int main()
{
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int s, d, cost;
		cin >> s >> d >> cost;
		graph[s].push_back(make_pair(d, cost));
	}
	vector<int> result = dijkstra(K, V + 1);

	for (int i = 1; i <= V; i++) {
		if (result[i] == INF)
			cout << "INF\n";
		else
			cout << result[i] << "\n";
	}
	return 0;
}