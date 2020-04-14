#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[1001], p[1001], Max;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i] = max(p[1] * i, p[i]);
	}
	for (int i = 2; i <= N; i++) {
		int l = 1, r = i - 1;
		while (l <= r) {
			dp[i] = max(dp[i], dp[l] + dp[r]);
			l++, r--;
		}
	}
	cout << dp[N] << '\n';
}