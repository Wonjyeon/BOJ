#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> tree[10001];
int N, MAX = -1;

int solve(int root) {
	int fir_M = 0, sec_M = 0;
	int size = tree[root].size();

	// 리프 노드
	if (size == 0) {
		return 0;
	}
	for (int i = 0; i < size; i++) {
		int val = tree[root][i].second + solve(tree[root][i].first);
		if (val > fir_M) {
			sec_M = fir_M;
			fir_M = val;
		}
		else if (val > sec_M)
			sec_M = val;
	}
	if (MAX < fir_M + sec_M)
		MAX = fir_M + sec_M;
	return fir_M;
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int p, c, value;
		cin >> p >> c >> value;
		tree[p].push_back({ c,value });
	}
	solve(1);
	cout << MAX << endl;
	return 0;
}