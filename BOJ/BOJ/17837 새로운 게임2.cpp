#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct Horse {
	int x, y, dir;
};

int N, K;
int map[13][13];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
vector<deque<int>> horse_map[13][13];
vector<Horse> horse;

int main() {
	horse.push_back(Horse({ 0,0,0 }));
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			deque<int> dq;
			horse_map[i][j].push_back(dq);
		}
	}
	for (int i = 1; i <= K; i++) {
		Horse h;
		cin >> h.x >> h.y >> h.dir;
		horse.push_back(h);
		horse_map[h.x][h.y][0].push_back(i);
	}
	int turn = 1;
	while (turn <= 1000) {
		if (turn == 2) {
			int debu = 1;
		}
		for (int i = 1; i <= K; i++) {
			int x = horse[i].x, y = horse[i].y, dir = horse[i].dir;
			int nx = x + dx[dir], ny = y + dy[dir];
			// 벽 or 파란색
			if (nx <= 0 || nx > N || ny <= 0 || ny > N || map[nx][ny] == 2) {
				// 방향 전환
				if (dir % 2 == 0) {
					dir -= 1;
					horse[i].dir = dir;
				}
				else {
					dir += 1;
					horse[i].dir = dir;
				}
				// 새로운 곳 확인
				nx = x + dx[dir], ny = y + dy[dir];
				// 또 벽 or 파란색 -> 이동하지 X.
				if (nx <= 0 || nx > N || ny <= 0 || ny > N || map[nx][ny] == 2)
					continue;
			}
			deque<int> dq = horse_map[x][y][0];
			deque<int> next_dq = horse_map[nx][ny][0];
			deque<int> move_dq;
			while (1) {
				int f = dq.front();
				dq.pop_front();
				move_dq.push_back(f);
				if (f == i) break;
			}
			horse_map[x][y][0] = dq;

			// 흰색 -> 나랑 내 위에 애들 이동.
			if (map[nx][ny] == 0) {
				while (!move_dq.empty()) {
					int b = move_dq.back();
					move_dq.pop_back();
					next_dq.push_front(b);
					horse[b].x = nx;
					horse[b].y = ny;
				}
				if (next_dq.size() >= 4) {
					cout << turn << endl;
					return 0;
				}
				horse_map[nx][ny][0] = next_dq;
			}
			// 빨간색 -> 순서 바꿔서 저장.
			else if (map[nx][ny] == 1) {
				while (!move_dq.empty()) {
					int f = move_dq.front();
					move_dq.pop_front();
					next_dq.push_front(f);
					horse[f].x = nx;
					horse[f].y = ny;
				}
				if (next_dq.size() >= 4) {
					cout << turn << endl;
					return 0;
				}
				horse_map[nx][ny][0] = next_dq;
			}
		}
		turn++;
	}
	cout << -1 << endl;
	return 0;
}