#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[1001], dp[1001][2];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i][0] = 1, dp[i][1] = 1;
	}
	for (int i = 1; i <= N; i++) {
		// 증가수열
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[i][0] < dp[j][0] + 1)
				dp[i][0] = dp[j][0] + 1;
		}
	}
	for (int i = N - 1; i >= 1; i--) {
		for (int j = N; j > i; j--) {
			if (arr[j] < arr[i] && dp[i][1] < dp[j][1] + 1)
				dp[i][1] = dp[j][1] + 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[i][0] + dp[i][1] - 1);
	}
	cout << ans << '\n';
	return 0;
}