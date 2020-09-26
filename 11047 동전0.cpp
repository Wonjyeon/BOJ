#include <iostream>
#include <algorithm>
using namespace std;

int N, K, ans = 0, coin[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		while (coin[i] <= K) {
			K -= coin[i];
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}