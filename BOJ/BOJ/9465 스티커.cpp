#include <iostream>
#include <algorithm>
using namespace std;

int T, N, s[2][100001], dp[2][100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= N; j++)
				cin >> s[i][j];
		dp[0][1] = s[0][1], dp[1][1] = s[1][1];
		for (int i = 2; i <= N; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + s[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + s[1][i];
		}
		cout << max(dp[0][N], dp[1][N]) << '\n';
	}
	return 0;
}