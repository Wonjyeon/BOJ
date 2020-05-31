#include <iostream>
#include <algorithm>
using namespace std;

int N, K, W[101], V[101], dp[101][100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];
	for (int i = 1; i <= N; i++) {
		int value = V[i], weight = W[i];
		for (int j = 1; j <= K; j++) {
			if (weight > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
		}
	}
	cout << dp[N][K] << endl;
}