#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Fish {
	int x, y, dist;
};
int N, map[20][20], visit[20][20];
int Sx, Sy, S_size = 2, time = 0, eat_num = 0;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
vector<Fish> V;

bool cmp(Fish f1, Fish f2) {
	if (f1.dist < f2.dist) return true;
	else if (f1.dist == f2.dist) {
		if (f1.x < f2.x) return true;
		else if (f1.x == f2.x)
			if (f1.y < f2.y) return true;
	}
	return false;
}
void BFS() {
	int Min_dist = 987654321;
	memset(visit, 0, sizeof(visit));
	V.clear();
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{ Sx, Sy } });
	visit[Sx][Sy] = 1;
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int dist = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] > S_size) continue;
			// 먹을 수 있는 물고기면
			if (map[nx][ny] > 0 && map[nx][ny] < S_size) {
				if (Min_dist < dist + 1) continue;
				Min_dist = dist + 1;
				Fish f;
				f.x = nx, f.y = ny, f.dist = dist + 1;
				V.push_back(f);
			}
			q.push({ dist + 1,{ nx,ny } });
			visit[nx][ny] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				Sx = i, Sy = j;
				map[i][j] = 0;
			}
		}
	}
	while (1) {
		BFS();
		int V_size = V.size();
		// 먹을 수 있는 물고기가 1개 이상
		if (V_size >= 1) {
			if (V_size > 1)
				sort(V.begin(), V.end(), cmp);
			Sx = V[0].x, Sy = V[0].y;
			map[V[0].x][V[0].y] = 0;
			time += V[0].dist;
			eat_num++;
			if (eat_num == S_size) {
				S_size++;
				eat_num = 0;
			}
		}
		else break;
	}
	cout << time << '\n';
}