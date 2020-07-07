#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, L, K;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;

	while (T--) {
		int p, a;
		vector<int> id, left, right;
		cin >> N >> L >> K;
		for (int i = 0; i < N; i++) {
			cin >> p >> a;
			id.push_back(a);
			if (a < 0)
				left.push_back(p);
			else
				right.push_back(L - p);
		}
		sort(left.rbegin(), left.rend());
		sort(right.rbegin(), right.rend());
		int cnt = 0, front = 0, end = N - 1, now_idx;
		while (1) {
			// case 1 : left를 제거
			if (right.empty() ||
				(!left.empty() && left[left.size() - 1] < right[right.size() - 1]) ||
				(!left.empty() && left[left.size() - 1] == right[right.size() - 1] && id[front] < id[end])) {
				left.pop_back();
				now_idx = id[front];
				front++;
			}
			// case 2 : right를 제거
			else if (left.empty() ||
				(!right.empty() && left[left.size() - 1] > right[right.size() - 1]) ||
				(!right.empty() && left[left.size() - 1] == right[right.size() - 1] && id[front] > id[end])) {
				right.pop_back();
				now_idx = id[end];
				end--;
			}
			cnt++;
			if (cnt == K) {
				cout << now_idx << '\n';
				break;
			}
		}
	}
	return 0;
}