#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> dp[i];
	int ans = dp[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - 1] + dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}