#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pa;
int R, C, N;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[101][101];
char map[101][101];
vector<pa> v;

void print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

bool isWall(int x, int y) {
	return x<1 || y<1 || x>R || y>C;
}

bool cmp(pa A, pa B) {
	if (A.first == B.first)
		return A.second < B.second;
	return A.first > B.first;
}

bool isCluster(int sx, int sy) {
	queue<pa> q;
	memset(visit, false, sizeof(visit));
	q.push({ sx, sy });
	visit[sx][sy] = true;
	v.push_back({ sx, sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == R)
			return true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isWall(nx, ny) || visit[nx][ny] || map[nx][ny] == '.')
				continue;
			q.push({ nx,ny });
			v.push_back({ nx,ny });
			visit[nx][ny] = true;
		}
	}
	return false;
}

void solution() {
	sort(v.begin(), v.end(), cmp);
	int flag = 0;
	while (1) {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			map[x + 1][y] = 'x';
			map[x][y] = '.';
			visit[x + 1][y] = true;
			if (x + 1 == R || (map[x + 2][y] == 'x' && !visit[x + 2][y]))
				flag = 1;
			v[i].first++;
		}
		if (flag == 1)
			return;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	string str;
	for (int i = 1; i <= R; i++) {
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j + 1] = str[j];
		}
	}
	cin >> N;
	int x, y;
	for (int n = 0; n < N; n++) {
		int flag = 0;
		cin >> x;
		x = R - x + 1;
		//¿ÞÂÊ.
		if (n % 2 == 0) {
			y = 1;
			while (y <= C) {
				if (map[x][y] == 'x') {
					flag = 1;
					break;
				}
				y++;
			}
		}
		else {
			y = C;
			while (y >= 1) {
				if (map[x][y] == 'x') {
					flag = 1;
					break;
				}
				y--;
			}
		}
		if (flag) {
			map[x][y] = '.';
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isWall(nx, ny) || map[nx][ny] == '.')
					continue;
				if (n == 3) {
					int debug = 1;
				}
				if (!isCluster(nx, ny)) {
					solution();
				}
				v.clear();
			}
		}
	}
	print();
	return 0;
}