#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dp[i];
	}
	int MAX = dp[0];
	for (int i = 1; i < N; i++) {
		if (MAX < 0 && dp[i] < 0) {
			MAX = max(MAX, dp[i]);
		}
		dp[i] += dp[i - 1];
		MAX = max(MAX, dp[i]);
		if (dp[i] < 0) dp[i] = 0;
	}
	cout << MAX << '\n';
}