#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vNum, vSort;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vNum.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> vNum[i];
		vSort.push_back(vNum[i]);
	}
	sort(vSort.begin(), vSort.end());
	vSort.erase(unique(vSort.begin(), vSort.end()), vSort.end());
	for (auto n : vNum) {
		int cnt = lower_bound(vSort.begin(), vSort.end(), n) - vSort.begin();
		cout << cnt << ' ';
	}
	cout << '\n';
	return 0;
}