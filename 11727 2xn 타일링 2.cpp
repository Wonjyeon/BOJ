#include <iostream>
using namespace std;

int N, dp[1001];

int main() {
	cin >> N;
	dp[1] = 1, dp[2] = 3;
	for (int i = 3; i <= N; i++)
		dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
	cout << dp[N] << '\n';
	return 0;
}