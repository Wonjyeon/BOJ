#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M, tree[1000000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll Max = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		Max = max(Max, tree[i]);
	}
	ll left = 0, right = Max, mid;
	ll prev_mid = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (mid == prev_mid) break;
		prev_mid = mid;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			ll tmp = tree[i] - mid;
			if (tmp <= 0) continue;
			sum += tmp;
		}
		if (sum < M)
			right = mid;
		else
			left = mid;
	}
	cout << mid << '\n';
	return 0;
}