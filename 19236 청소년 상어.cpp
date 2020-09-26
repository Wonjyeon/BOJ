#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fish {
	int x, y, dir, dead;
};

int ans = 0;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
vector<vector<int>> map(4, vector<int>(4, 0));
vector<Fish> fishes(18);

void moving(int sum) {
	// ����� �̵�
	for (int i = 1; i <= 16; i++) {
		if (fishes[i].dead == 1)	// �̹� �׾����� continue
			continue;
		int x = fishes[i].x;
		int y = fishes[i].y;
		int dir = fishes[i].dir;

		for (int d = 0; d < 8; d++) {
			int now_dir = (dir + d) % 8;
			int nx = x + dx[now_dir], ny = y + dy[now_dir];
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || map[nx][ny] == 17)	// �̵��� �� ����
				continue;
			// �̵� ����
			fishes[i].dir = now_dir;
			if (map[nx][ny] == 0) {		// �� ��
				map[nx][ny] = i;
				fishes[i].x = nx;
				fishes[i].y = ny;
				map[x][y] = 0;
			}
			else {
				swap(fishes[i].x, fishes[map[nx][ny]].x);
				swap(fishes[i].y, fishes[map[nx][ny]].y);
				swap(map[x][y], map[nx][ny]);
			}
			break;
		}
	}
	// ��� �̵�
	int sx = fishes[17].x;
	int sy = fishes[17].y;
	int sdir = fishes[17].dir;
	int nsx = sx, nsy = sy;
	while (1) {
		nsx += dx[sdir];
		nsy += dy[sdir];
		if (nsx < 0 || nsx >= 4 || nsy < 0 || nsy >= 4)
			break;
		if (map[nsx][nsy] == 0)
			continue;
		// ���� ����Ⱑ �ִٸ�
		vector<vector<int>> tempMap = map;
		vector<Fish> tempFish = fishes;
		int dfishId = map[nsx][nsy];
		fishes[17] = fishes[dfishId];
		fishes[dfishId].dead = 1;
		map[nsx][nsy] = 17;
		map[sx][sy] = 0;
		moving(sum + dfishId);
		map = tempMap;
		fishes = tempFish;
	}
	// �� �̻� ��� �̵��� �� ����
	ans = max(ans, sum);
	return;
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int idx, dir;
			cin >> idx >> dir;
			map[i][j] = idx;
			fishes[idx] = Fish{ i, j, dir - 1, 0 };
		}
	}
	ans += map[0][0];					// (0, 0)�� ����� id
	fishes[17] = fishes[map[0][0]];		// ��� �̵�
	fishes[map[0][0]].dead = 1;			// ���� �ִ� ���� ó��
	map[0][0] = 17;						// (0, 0)�� ��� id
	moving(ans);
	cout << ans << '\n';
	return 0;
}