#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

struct Element {
	int num;
	char color;
};

int N, ans = -INF;
bool visit[10];
int start[4][2] = { { 0,0 },{ 0,1 },{ 1,0 },{ 1,1 } };
int efficiacy[10][4][4][4];
char element[10][4][4][4];
vector<int> visit_v;
Element map[5][5];

int R, G, B, Y;

void rotateArr(int type, int dir) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			efficiacy[type][dir][i][j] = efficiacy[type][dir - 1][3 - j][i];
			element[type][dir][i][j] = element[type][dir - 1][3 - j][i];
		}
	}
}

void write(int i, int r, int l) {
	int idx = visit_v[i];

	// 격자에 값 쓰기.
	int sx = start[l][0], sy = start[l][1];
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			map[sx + x][sy + y].num += efficiacy[idx][r][x][y];
			if (map[sx + x][sy + y].num < 0)
				map[sx + x][sy + y].num = 0;
			else if (map[sx + x][sy + y].num > 9)
				map[sx + x][sy + y].num = 9;
			if (element[idx][r][x][y] != 'W')
				map[sx + x][sy + y].color = element[idx][r][x][y];
		}
	}
}

/* 3개의 원소에 대해서, 회전 횟수와 시작 위치 결정 */
void dfs2(int idx, int depth) {
	if (depth == 3) {
		int r_cnt = 0, b_cnt = 0, g_cnt = 0, y_cnt = 0;
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (map[i][j].color == 'R')
					r_cnt += map[i][j].num;
				else if (map[i][j].color == 'B')
					b_cnt += map[i][j].num;
				else if (map[i][j].color == 'G')
					g_cnt += map[i][j].num;
				else if (map[i][j].color == 'Y')
					y_cnt += map[i][j].num;
			}
		}
		sum = 7 * r_cnt + 5 * b_cnt + 3 * g_cnt + 2 * y_cnt;
		ans = max(ans, sum);
		return;
	}
	for (int i = idx; i < 3; i++) {
		for (int r = 0; r < 4; r++) {
			for (int l = 0; l < 4; l++) {
				Element tmp[5][5];
				for (int x = 0; x < 5; x++) {
					for (int y = 0; y < 5; y++) {
						tmp[x][y] = map[x][y];
					}
				}
				write(i, r, l);
				dfs2(i + 1, depth + 1);
				for (int x = 0; x < 5; x++) {
					for (int y = 0; y < 5; y++) {
						map[x][y] = tmp[x][y];
					}
				}
			}
		}
	}
}

/* 3개의 원소 선택*/
void dfs(int depth) {
	if (depth == 3) {
		dfs2(0, 0);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		visit_v.push_back(i);
		dfs(depth + 1);
		visit[i] = false;
		visit_v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	Element e = Element{ 0, 'W' };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map[i][j] = e;
		}
	}
	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> efficiacy[n][0][i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> element[n][0][i][j];
			}
		}
		for (int d = 1; d <= 3; d++)
			rotateArr(n, d);
	}
	dfs(0);
	cout << ans << '\n';
}