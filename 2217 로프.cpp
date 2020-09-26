#include <iostream>
#include <algorithm>
using namespace std;

int N, rope[100000];
long long ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + N);
	ans = rope[N - 1];
	int cnt = 2;
	for (int i = N - 2; i >= 0; i--) {
		if (cnt*rope[i] >= ans) {
			ans = cnt*rope[i];
		}
		cnt++;
	}
	cout << ans << '\n';
	return 0;
}