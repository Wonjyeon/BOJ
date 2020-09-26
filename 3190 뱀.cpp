#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int N, K, L;

int map[100][100];


int chk(int x, int y) {
	return x >= 0 && y >= 0 && x < N&&y < N;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	vector<pair<int, char>> v;
	queue<pair<int, int>> q;

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int a;	char c;
		cin >> a >> c;
		v.push_back({ a,c });
	}
	int dir = 1, v_idx = 0, time = 0;
	int hx = 0, hy = 0;

	// ²¿¸® Á¤º¸¸¦ ´ã´Â queue
	q.push({ 0,0 });
	while (1) {
		if (v_idx < L) {
			int dir_time = v[v_idx].first;
			char change_dir = v[v_idx].second;

			if (time == dir_time) {
				if (change_dir == 'D') {
					dir = (dir + 1) % 4;
				}
				else if (change_dir == 'L') {
					dir -= 1;
					if (dir < 0)
						dir = 3;
				}
				v_idx++;
			}
		}

		hx += dx[dir];
		hy += dy[dir];

		// º®À» ¸¸³µ°Å³ª ÀÚ½ÅÀÇ ¸öÀ» ¸¸³µ´Ù¸é
		if (!chk(hx, hy) || map[hx][hy] == 1) {
			break;
		}
		// ºó °ø°£ÀÌ¶ó¸é ²¿¸® »èÁ¦.
		else if (map[hx][hy] == 0) {
			int tx = q.front().first;
			int ty = q.front().second;
			map[tx][ty] = 0;
			q.pop();
		}
		map[hx][hy] = 1;
		q.push({ hx,hy });


		time++;
	}
	cout << time + 1 << endl;
	return 0;
}