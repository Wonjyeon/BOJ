#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Fish {
	int r, c, s, d, z;
};
Fish fish[10001];
int R, C, M, ans = 0;
vector<int> arr[101][101];
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };

/*
	���� ������ ������ ���� ���� ���� ����⸦ ����
	����⸦ ���� ������ ans++
	���� ������ ���Ը� 0����!
*/
void Catch(int row) {
	for (int col = 1; col <= R; col++) {
		if (arr[col][row].size() > 0) {
			int idx = arr[col][row][0];
			ans += fish[idx].z;
			fish[idx].z = 0;
			break;
		}
	}
}
/*
	arr �迭 : �ش� ��ġ�� � ����Ⱑ �ִ��� idx ������ ��� ����.
*/
void Move() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			arr[i][j].clear();
		}
	}
	for (int i = 1; i <= M; i++) {
		// ������� ���԰� 0���� ũ�ٸ� ���� ����ִ� ��
		if (fish[i].z > 0) {
			int x = fish[i].r, y = fish[i].c, dir = fish[i].d;
			int s = fish[i].s;

			for (int k = 0; k < s; k++) {
				int nx = x + dx[dir], ny = y + dy[dir];
				// ���� ������ ����� ������ ��ȯ����� ��
				if (nx<1 || ny<1 || nx>R || ny>C) {
					if (dir == 1) dir = 2;
					else if (dir == 2) dir = 1;
					else if (dir == 3) dir = 4;
					else dir = 3;
				}
				x += dx[dir];
				y += dy[dir];
			}
			fish[i].r = x, fish[i].c = y, fish[i].d = dir;
			// �̹� �ٸ� ����Ⱑ ������
			if (arr[x][y].size() > 0) {
				int idx = arr[x][y][0];
				// �̹� �ִ� ������ ���� ������ ���� �� ū�� ��. ū ���� ����. ���� ���� ���Ը� 0����!
				if (fish[idx].z < fish[i].z) {
					arr[x][y].pop_back();
					arr[x][y].push_back(i);
					fish[idx].z = 0;
				}
				else {
					fish[i].z = 0;
				}
			}
			// ������ ���� ����⸦ ����
			else {
				arr[x][y].push_back(i);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		cin >> fish[i].r >> fish[i].c >> fish[i].s >> fish[i].d >> fish[i].z;
		int s = fish[i].s;
		if (fish[i].d == 1 || fish[i].d == 2)
			fish[i].s = fish[i].s % (2 * R - 2);
		else
			fish[i].s = fish[i].s % (2 * C - 2);
		arr[fish[i].r][fish[i].c].push_back(i);
	}
	// ���ʿ� ����Ⱑ �ƿ� ������
	if (M == 0) {
		cout << "0\n";
		return 0;
	}
	// ������ �� ĭ�� �ű�鼭 ����
	for (int i = 1; i <= C; i++) {
		Catch(i);
		Move();
	}
	cout << ans << '\n';
	return 0;
}