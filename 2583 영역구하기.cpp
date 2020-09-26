#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K, cnt = 0;
int map[100][100];
int visit[100][100];
vector<int> answer;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void dfs(int x, int y) {
	cnt++;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
			if (!visit[nx][ny] && !map[nx][ny])
			{
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				map[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j] && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				answer.push_back(cnt);
			}
		}
	}
	cout << answer.size() << endl;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";
	return 0;
}