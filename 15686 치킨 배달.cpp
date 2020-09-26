#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, M, map[50][50], visit[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected;
int minSum = INF;

void distance() {
	int minD = INF;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				minD = INF;
				for (int k = 0; k < selected.size(); k++) {
					int x_D = abs(i - selected[k].first);
					int y_D = abs(j - selected[k].second);
					minD = min(minD, x_D + y_D);
					if (minD == 1)
						break;
				}
				sum = sum + minD;
			}
		}
	}
	minSum = min(minSum, sum);
}

void solve(int start, int cnt) {
	if (cnt == M) {
		distance();
		return;
	}
	for (int i = start; i < chicken.size(); i++) {
		selected.push_back({ chicken[i].first,chicken[i].second });
		solve(i + 1, cnt + 1);
		selected.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	solve(0, 0);
	cout << minSum << endl;
	return 0;
}