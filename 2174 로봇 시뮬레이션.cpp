#include <iostream>
using namespace std;

struct Robot {
	int x, y, dir;
};
struct Command {
	int rid, cnt;
	char cmd;
};
int A, B, N, M, errId1 = 0, errId2 = 0;
int map[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
Robot robots[101];
Command commands[101];

void solve() {
	for (int i = 1; i <= M; i++) {
		// command 정보
		int rid = commands[i].rid;
		int cnt = commands[i].cnt;
		char cmd = commands[i].cmd;

		// robot 정보
		int x = robots[rid].x;
		int y = robots[rid].y;
		int dir = robots[rid].dir;

		if (cmd == 'R') {
			dir = (dir + cnt) % 4;
			robots[rid].dir = dir;
		}
		else if (cmd == 'L') {
			dir = (dir + 3 * cnt) % 4;
			robots[rid].dir = dir;
		}
		else {
			int nx = x;
			int ny = y;
			for (int i = 1; i <= cnt; i++) {
				nx += dx[dir];
				ny += dy[dir];
				if (nx <= 0 || nx > A || ny <= 0 || ny > B) {
					errId1 = rid;
					return;
				}
				if (map[nx][ny] != 0) {
					errId1 = rid;
					errId2 = map[nx][ny];
					return;
				}
			}
			map[x][y] = 0;
			robots[rid].x = nx;
			robots[rid].y = ny;
			map[nx][ny] = rid;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> N >> M;
	char d;
	for (int i = 1; i <= N; i++) {
		cin >> robots[i].x >> robots[i].y >> d;
		if (d == 'N') robots[i].dir = 0;
		else if (d == 'E') robots[i].dir = 1;
		else if (d == 'S') robots[i].dir = 2;
		else if (d == 'W')robots[i].dir = 3;
		map[robots[i].x][robots[i].y] = i;
	}
	for (int i = 1; i <= M; i++) {
		cin >> commands[i].rid >> commands[i].cmd >> commands[i].cnt;
	}
	solve();
	if (errId1 == 0)
		cout << "OK\n";
	else if (errId2 == 0)
		cout << "Robot " << errId1 << " crashes into the wall\n";
	else
		cout << "Robot " << errId1 << " crashes into robot " << errId2 << '\n';
	return 0;
}
