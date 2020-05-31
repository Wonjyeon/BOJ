#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[1001], dp[1001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) dp[i] = dp[j] + arr[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
}