#include <iostream>
using namespace std;

int N, dp[31];

int main() {
	cin >> N;
	dp[0] = 1, dp[2] = 3;
	for (int i = 4; i <= N; i += 2) {
		dp[i] = 3 * dp[i - 2];
		for (int j = i - 4; j >= 0; j--) {
			dp[i] += 2 * dp[j];
		}
	}
	cout << dp[N] << '\n';
}