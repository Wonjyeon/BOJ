#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int N, t[16] = { 0 }, p[16] = { 0 }, dp[16] = { 0 };
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> p[i];
		dp[i] = p[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (i - j >= t[j])
				dp[i] = max(p[i] + dp[j], dp[i]);
		}
	}
	int max = 0;

	for (int i = 1; i <= N; i++)
	{
		if (i + t[i] <= N + 1) {
			if (max < dp[i])
				max = dp[i];
		}
	}
	cout << max << endl;
	return 0;
}