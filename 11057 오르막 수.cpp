#include <iostream>
using namespace std;

int N, dp[1001][10];

int main() {
	cin >> N;
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[N][i];
	cout << ans % 10007 << endl;
	return 0;
}