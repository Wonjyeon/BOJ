#include <iostream>
using namespace std;

long long dp[101] = { 0, };
int main() {
	int T, N;
	cin >> T;
	dp[1] = dp[2] = dp[3] = 1;
	for (int i = 4; i <= 100; i++)
		dp[i] = dp[i - 3] + dp[i - 2];
	while (T--) {
		cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}