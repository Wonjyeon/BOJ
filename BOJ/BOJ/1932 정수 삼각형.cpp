#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[500][500];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	cout << dp[0][0] << '\n';
}