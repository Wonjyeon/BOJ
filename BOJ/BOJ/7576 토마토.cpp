#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int d[MAX][MAX];
int tomato[MAX][MAX];

int main()
{
	int N, M;
	cin >> M >> N;

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
			{
				d[i][j] = 0;
				q.push({ i,j });
			}
			else
				d[i][j] = -1;
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N&&ny >= 0 && ny < M) {
				if (tomato[nx][ny] == 0 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result = max(result, d[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0 && d[i][j] == -1) {
				result = -1;
			}
		}
	}
	cout << result;
}