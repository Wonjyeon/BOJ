#include <iostream>
using namespace std;

int N, ans, dp[10003], wine[10001];
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> wine[i];
	if (N == 1) {
		cout << wine[1] << '\n';
		return 0;
	}
	dp[1] = wine[1], dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= N; i++) {
		int Max = max(dp[i - 1], wine[i] + dp[i - 2]);
		Max = max(Max, wine[i] + wine[i - 1] + dp[i - 3]);
		dp[i] = Max;
	}
	cout << dp[N] << '\n';
}