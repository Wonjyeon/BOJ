#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k, map[101][101];
int N = 3, M = 3, ans = 0, max_row = 0, max_col = 0;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second < p2.second) return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first) return true;
	}
	return false;
}

int col_solve() {
	for (int i = 1; i <= N; i++) {
		vector<pair<int, int>> v;
		int maxNum = 0;
		int IDX[101] = { 0, };
		for (int j = 1; j <= M; j++) {
			int num = map[i][j];
			if (num == 0) continue;
			IDX[num]++;
			if (maxNum < num) maxNum = num;
		}
		for (int k = 1; k <= maxNum; k++) {
			if (IDX[k] > 0) {
				v.push_back({ k, IDX[k] });
			}
		}
		sort(v.begin(), v.end(), cmp);
		int index = 1;
		for (int k = 0; k < v.size(); k++) {
			map[i][index++] = v[k].first;
			map[i][index++] = v[k].second;
			if (index == 101) break;
		}
		if (max_row < v.size() * 2)
			max_row = v.size() * 2;
		for (int k = v.size() * 2 + 1; k <= max_row; k++) {
			map[i][k] = 0;
		}
		if (map[r][c] == k) return true;
	}
	return false;
}
int row_solve() {
	for (int i = 1; i <= M; i++) {
		vector<pair<int, int>> v;
		int maxNum = 0;
		int IDX[101] = { 0, };
		for (int j = 1; j <= N; j++) {
			int num = map[j][i];
			if (num == 0) continue;
			IDX[num]++;
			if (maxNum < num) maxNum = num;
		}
		for (int k = 1; k <= maxNum; k++) {
			if (IDX[k] > 0) {
				v.push_back({ k, IDX[k] });
			}
		}
		sort(v.begin(), v.end(), cmp);
		int index = 1;
		for (int k = 0; k < v.size(); k++) {
			map[index++][i] = v[k].first;
			map[index++][i] = v[k].second;
			if (index == 101) break;
		}
		if (max_col < v.size() * 2)
			max_col = v.size() * 2;
		for (int k = v.size() * 2 + 1; k <= max_col; k++) {
			map[k][i] = 0;
		}
		if (map[r][c] == k) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> map[i][j];
	if (map[r][c] == k) {
		cout << "0\n";
		return 0;
	}
	while ((N < 101 || M < 101) && ans <= 100) {
		// 행 정렬
		if (N >= M) {
			ans++;
			if (col_solve()) break;
			M = max_row;
		}
		// 열 정렬
		else {
			ans++;
			if (row_solve()) break;
			N = max_col;
		}
	}
	if (ans > 100) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}