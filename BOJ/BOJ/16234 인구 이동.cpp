#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int visit[50][50];
int map[50][50];
int N, L, R, flag = 0;
int group_id = 0;


void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
}

int chk(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

void bfs(int s, int e) {
	int sum = map[s][e];
	int avg = 0;
	int cnt = 1;

	visit[s][e] = group_id;
	queue<pair<int, int>> q;
	queue<pair<int, int>> group_q;
	q.push({ s,e });
	group_q.push({ s,e });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int num = abs(map[nx][ny] - map[x][y]);
			if (!chk(nx, ny))
				continue;
			if (!visit[nx][ny] && num >= L&&num <= R) {
				visit[nx][ny] = group_id;
				sum += map[nx][ny];
				cnt++;
				q.push({ nx,ny });
				group_q.push({ nx,ny });
				flag = 1;
			}

		}
	}
	avg = sum / cnt;
	while (!group_q.empty()) {
		int x = group_q.front().first;
		int y = group_q.front().second;
		map[x][y] = avg;
		group_q.pop();
	}
}

int main() {
	int time = 0;

	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		group_id = 1;
		flag = 0;
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					bfs(i, j);
					group_id++;
				}
			}
		}
		if (flag == 1)
			time++;
		else
			break;
	}
	printf("%d\n", time);

}