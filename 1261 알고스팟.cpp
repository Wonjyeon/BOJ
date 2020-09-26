#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
int dist[101][101], map[101][101], N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = INF;
		}
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{ 0,0 } });
	dist[0][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			int nextcost = map[nx][ny];
			if (chk(nx, ny) && dist[nx][ny] > cost + nextcost) {
				dist[nx][ny] = cost + nextcost;
				pq.push({ -dist[nx][ny],{ nx,ny } });
			}
		}
	}
	cout << dist[N - 1][M - 1] << '\n';
	return 0;
}
