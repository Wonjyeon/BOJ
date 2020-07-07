#include <iostream>
#include <algorithm>
using namespace std;

int color[1000][3];
int dp[1000][3];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}

	for (int i = 1; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + color[i][2];
	}
	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << endl;
	return 0;
}