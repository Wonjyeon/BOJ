#include <iostream>
#include <queue>
using namespace std;

int N, M, H, total;
int map[100][100][100];
bool visit[100][100][100];
queue<pair<pair<int, int>, int>> q;
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

bool chk(int x, int y, int z) {
	return x >= 0 && x < N&&y >= 0 && y < M&&z >= 0 && z < H;
}

int bfs() {
	int time = 0;
	while (!q.empty()) {
		int size = q.size();
		time++;
		while (size--) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
				if (!chk(nx, ny, nz) || visit[nx][ny][nz]) continue;
				if (map[nx][ny][nz] != 0) continue;
				visit[nx][ny][nz] = 1;
				map[nx][ny][nz] = 1;
				q.push({ { nx,ny } ,nz });
				total--;
				if (total == 0) return time;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ { i, j }, k });
					visit[i][j][k] = true;
				}
				else if (map[i][j][k] == 0) total++;
			}
		}
	}
	if (total == 0) cout << 0 << '\n';
	else cout << bfs() << '\n';
}