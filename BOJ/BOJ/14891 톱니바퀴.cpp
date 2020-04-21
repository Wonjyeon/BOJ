#include <iostream>
#include <queue>
#include <cmath>
#include <math.h>
using namespace std;

int K, wheel[5][8];
int dx[] = { -1,1 };

void solve(int num, int dir) {
	bool visit[5] = { false, };
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push({ num, dir });
	v.push_back({ num, dir });
	visit[num] = true;
	while (!q.empty()) {
		int x = q.front().first, d = q.front().second;
		q.pop();
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			if (nx <= 0 || nx>4) continue;
			if (visit[nx]) continue;
			//왼쪽애랑 비교
			if (nx < x) {
				if (wheel[nx][2] != wheel[x][6]) {
					visit[nx] = 1;
					q.push({ nx,d*(-1) });
					v.push_back({ nx, d*(-1) });
				}
			}
			// 오른쪽애랑 비교
			else {
				if (wheel[nx][6] != wheel[x][2]) {
					visit[nx] = 1;
					q.push({ nx, d*(-1) });
					v.push_back({ nx, d*(-1) });
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int num = v[i].first, dir = v[i].second;
		//왼쪽으로 이동
		if (dir == -1) {
			int temp = wheel[num][0];
			for (int i = 0; i < 7; i++) {
				wheel[num][i] = wheel[num][i + 1];
			}
			wheel[num][7] = temp;
		}
		//오른쪽으로 이동
		else {
			int temp = wheel[num][7];
			for (int i = 7; i >= 1; i--) {
				wheel[num][i] = wheel[num][i - 1];
			}
			wheel[num][0] = temp;
		}
	}
}

int main() {
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &wheel[i][j]);
	cin >> K;
	while (K--) {
		int num, dir;
		cin >> num >> dir;
		solve(num, dir);
	}
	for (int i = 1; i <= 4; i++) {
		if (wheel[i][0] == 0) continue;
		ans += pow(2, i - 1);
	}
	cout << ans << '\n';
}