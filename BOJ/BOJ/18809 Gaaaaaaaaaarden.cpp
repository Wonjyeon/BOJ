#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, G, R, available, ans = 0, map[50][50];
int visit[10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> v;
vector<pair<int, int>> Green;
vector<pair<int, int>> Red;


void bfs() {
	int flower = 0;
	int temp[50][50] = { 0, };
	queue<pair<int, int>> red, green;
	for (int i = 0; i < Green.size(); i++) {
		green.push({ Green[i].first, Green[i].second });
		temp[Green[i].first][Green[i].second] = 1;
	}
	for (int i = 0; i < Red.size(); i++) {
		red.push({ Red[i].first, Red[i].second });
		temp[Red[i].first][Red[i].second] = -1;
	}

	while (!green.empty() && !red.empty()) {
		int green_size = green.size();
		int red_size = red.size();
		while (red_size--) {
			int x = red.front().first, y = red.front().second;
			red.pop();
			if (temp[x][y] == 1000) continue;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;
				if (map[nx][ny] == 0)
					continue;
				// 새로 추가
				if (temp[nx][ny] == 0) {
					temp[nx][ny] = temp[x][y] - 1;
					red.push({ nx,ny });
				}
			}
		}
		while (green_size--) {
			int x = green.front().first, y = green.front().second;
			green.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;
				if (map[nx][ny] == 0)
					continue;
				// 새로 추가
				if (temp[nx][ny] == 0) {
					green.push({ nx,ny });
					temp[nx][ny] = temp[x][y] + 1;
				}
				else if (temp[nx][ny] == (temp[x][y] + 1)*-1) {
					temp[nx][ny] = 1000;
					flower++;
				}
			}
		}

	}
	ans = max(ans, flower);
}

void select(int idx, int gcnt, int rcnt) {
	if (gcnt + rcnt > (available - idx)) return;
	if (gcnt == 0 && rcnt == 0) {
		bfs();
		return;
	}
	int x = v[idx].first, y = v[idx].second;
	// 해당 위치에 아무것도 뿌리지 않겠다.
	select(idx + 1, gcnt, rcnt);
	// 해당 위치에 초록색을 뿌리겠다.
	if (gcnt > 0) {
		Green.push_back({ x,y });
		select(idx + 1, gcnt - 1, rcnt);
		Green.pop_back();
	}
	// 해당 위치에 빨간색을 뿌리겠다.
	if (rcnt > 0) {
		Red.push_back({ x,y });
		select(idx + 1, gcnt, rcnt - 1);
		Red.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
	available = v.size();
	select(0, G, R);
	cout << ans << '\n';
	return 0;
}