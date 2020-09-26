#include <iostream>
#include <queue>
using namespace std;

int N, M, sx, sy, ex, ey;
int dp[55][55], g[55][55];
char a[55][55];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int main() {
	cin >> N >> M;

	// 지도 배열 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S')
				sx = i, sy = j;
			else if (a[i][j] == 'F')
				ex = i, ey = j;
		}
	}

	// g배열 (가중치 정보) -> 높을수록 안 좋음.
	// 쓰레기 : 3000, 쓰레기 옆 : 1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 'g')
				g[i][j] = 3000;
			else if (a[i][j] == '.') {
				int f = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (chk(nx, ny) && a[nx][ny] == 'g')
						f = 1;
				}
				if (f)
					g[i][j] = 1;
			}
		}
	}

	// dp 초기화
	// 해당 위치까지의 최소 가중치값 정보
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			dp[i][j] = -1;
		}
	}

	priority_queue < pair<int, pair<int, int>>> pq;
	pq.push({ g[sx][sy],{ sx,sy } });
	while (pq.size()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();

		if (dp[x][y] == -1) {
			dp[x][y] = cost;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (chk(nx, ny) && dp[nx][ny] == -1)
					pq.push({ -cost - g[nx][ny],{ nx,ny } });
			}
		}
	}
	printf("%d %d\n", dp[ex][ey] / 3000, dp[ex][ey] % 3000);
	return 0;
}