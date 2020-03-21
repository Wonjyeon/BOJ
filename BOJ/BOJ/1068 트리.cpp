#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];
int N, key, ans = 0;

void solve(int root) {
	int cnt = 0;
	for (int i = 0; i < tree[root].size(); i++) {
		if (tree[root][i] == key)
			continue;
		solve(tree[root][i]);
		cnt++;
	}
	if (cnt == 0) {
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int root;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		if (p == -1) {
			root = i;
			continue;
		}

		tree[p].push_back(i);
	}
	cin >> key;
	if (key == root) {
		cout << 0 << endl;
		return 0;
	}
	solve(root);
	cout << ans << endl;
}