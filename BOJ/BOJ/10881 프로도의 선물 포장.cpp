#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, boxes[3][2], ans = 987654321;
bool visit[3];

void solve(int type, int cnt, int idx) {
	if (cnt == 3) {
		int aw = boxes[0][0], ah = boxes[0][1];
		int bw = boxes[1][0], bh = boxes[1][1];
		int cw = boxes[2][0], ch = boxes[2][1];
		int width = 0, height = 0;

		if (visit[0]) swap(aw, ah);
		if (visit[1]) swap(bw, bh);
		if (visit[2]) swap(cw, ch);

		if (type == 1) {
			width = aw + bw + cw;
			height = max(max(ah, bh), ch);
		}
		else if (type == 2) {
			width = max(aw + bw, cw);
			height = max(ah, bh) + ch;
		}
		else if (type == 3) {
			width = max(bw + cw, aw);
			height = max(bh, ch) + ah;
		}
		else if (type == 4) {
			width = max(aw + cw, bw);
			height = max(ah, ch) + bh;
		}
		ans = min(ans, width*height);
		return;
	}
	for (int i = idx; i < 3; i++) {
		solve(type, i + 1, cnt + 1);
		visit[i] = 1;
		solve(type, i + 1, cnt + 1);
		visit[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 987654321;
		for (int i = 0; i < 3; i++)
			cin >> boxes[i][0] >> boxes[i][1];
		for (int i = 1; i <= 4; i++)
			solve(i, 0, 0);
		cout << ans << '\n';
	}
}
