#include <iostream>
#include <algorithm>
using namespace std;

int N, value[100001], dp[3][100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> value[i];
	dp[0][1] = 0, dp[1][1] = value[1], dp[2][1] = value[1];
	for (int i = 2; i <= N; i++) {
		dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]);
		dp[1][i] = dp[0][i - 1] + value[i];
		dp[2][i] = dp[1][i - 1] + value[i];
	}
	cout << max(max(dp[0][N], dp[1][N]), dp[2][N]) << endl;
	return 0;
}