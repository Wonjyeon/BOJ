#include <iostream>
#include <algorithm>
using namespace std;

int s[301];
int dp[301][2];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s[i];
	}
	dp[1][1] = s[1];
	dp[1][2] = 0;
	dp[2][1] = s[2];
	dp[2][2] = dp[1][1] + s[2];

	for (int i = 3; i <= N; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + s[i];
		dp[i][2] = dp[i - 1][1] + s[i];
	}
	cout << max(dp[N][1], dp[N][2]) << endl;
	return 0;
}