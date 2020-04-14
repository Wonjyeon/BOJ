#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[1001], arr[1001], ans = 1;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] <= arr[j]) continue;
			dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}