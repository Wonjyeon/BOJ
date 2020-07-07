#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v, vc;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		vc.push_back(v[i]);
	}
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(), vc.end()), vc.end());
	for (auto i : v) {
		int cnt = lower_bound(vc.begin(), vc.end(), i) - vc.begin();
		cout << cnt << ' ';
	}
	cout << '\n';
	return 0;
}