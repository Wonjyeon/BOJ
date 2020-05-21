#include <iostream>
#include <climits>
using namespace std;

int K, N, arr[10000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> arr[i];
	long long ans = 0, sum = 0, left = 1, right = INT_MAX, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < K; i++)
			sum += arr[i] / mid;
		if (sum < N)
			right = mid - 1;
		else {
			left = mid + 1;
			ans = mid;
		}
	}
	cout << ans << '\n';
}